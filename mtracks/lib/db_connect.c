#include <stddef.h>
#include <stdio.h>

#include "mtracks_stdlib.h"
#include "mtracks_sqlite.h"
#include "mtracks_string.h"
#include "receipt.h"
#include "tracksql.h"

#ifdef _WIN32
#define HOMEDIR_ENV ("UserProfile")
#define DIRSEP ('\\')
#else
#define HOMEDIR_ENV ("HOME")
#define DIRSEP ('/')
#endif

#define DEFAULT_DB_NAME (".mtracks.db")

static char *get_default_db_path(void);
static int build_tables(sqlite3 *);

/**
 * @brief Get the default database path.
 * @return The default database path.
 * @remarks Caller must free the returned buffer.
 */
static char *get_default_db_path(void)
{
  const char *homedir = getenv(HOMEDIR_ENV);
  size_t buflen = strlen(homedir) + 1 + strlen(DEFAULT_DB_NAME) + 1;
  char *dbpath = xcalloc(buflen, 1);

  if (snprintf(dbpath, buflen, "%s%c%s", homedir, DIRSEP, DEFAULT_DB_NAME)
      != (int)buflen-1) {
    fprintf(stderr, "Failed to populate default database path buffer.\n");
    memset(dbpath, '\0', buflen);
  }

  return (dbpath);
}

/**
 * @brief Add the database tables if they don't exist.
 * @return The SQLite error code.
 */
static int build_tables(sqlite3 *dbconn)
{
  int sql_errno = SQLITE_ERROR;
  char stmt_str[MTRACKS_STATEMENT_MAX];

  memset(stmt_str, '\0', sizeof (stmt_str));

  /* TODO check snprintf() return code */
  snprintf(stmt_str, sizeof (stmt_str),
           "CREATE TABLE IF NOT EXISTS vendors(vendor char(%d), category char(%d), PRIMARY KEY(vendor));",
           VENDORSIZ, CATEGORYSIZ);

  if ((sql_errno = execute_one_step_statement(dbconn, stmt_str)) != SQLITE_OK) {
    goto out;
  }

  memset(stmt_str, '\0', sizeof (stmt_str));

  /* TODO check snprintf() return code */
  snprintf(stmt_str, sizeof (stmt_str),
           "CREATE TABLE IF NOT EXISTS receipts(date date, amount decimal(%d,%d), vendor char(%d), FOREIGN KEY(vendor) REFERENCES vendors(vendor) ON DELETE SET NULL ON UPDATE CASCADE, PRIMARY KEY(date, amount, vendor));", AMOUNTSIZ, AMOUNTDEC, VENDORSIZ);

  if ((sql_errno = execute_one_step_statement(dbconn, stmt_str)) != SQLITE_OK) {
    goto out;
  }
  
out:
  return (sql_errno);
}

/**
 * @brief Create/connect to the SQLite database.
 * @param(in) dbpath The database file to create.
 * @return The sqlite3 connection data structure if successful, NULL otherwise.
 */
sqlite3 *db_connect(const char *dbpath)
{
  int sql_errno = SQLITE_OK;
  sqlite3 *dbconn = NULL;
  char *the_dbpath = NULL;

  if (dbpath) {
    the_dbpath = xstrdup(dbpath);
  } else {
    the_dbpath = get_default_db_path();
  }

  if ((sql_errno = sqlite3_open(the_dbpath, &dbconn)) != SQLITE_OK) {
    fprintf(stderr,
            "Failed to open a connection to the database file '%s' (%s).\n",
            the_dbpath, mtracks_sqlite_strerror(sql_errno));

    if (dbconn && (sql_errno = sqlite3_close(dbconn)) != SQLITE_OK) {
      fprintf(stderr,
              "Failed to tidy up SQL connection resource (%s).\n",
              mtracks_sqlite_strerror(sql_errno));
    }

    dbconn = NULL;
    goto out;
  }

  if (build_tables(dbconn) != 0) {
    fprintf(stderr, "Failed to create database tables.\n");
    if ((sql_errno = sqlite3_close(dbconn)) != SQLITE_OK) {
      fprintf(stderr,
              "Failed to tidy up SQL connection resource (%s).\n",
              mtracks_sqlite_strerror(sql_errno));
    }

    dbconn = NULL;
    goto out;
  }

out:
  free(the_dbpath);
  the_dbpath = NULL;

  return (dbconn);
}
