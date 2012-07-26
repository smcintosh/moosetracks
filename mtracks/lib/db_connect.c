#include <stddef.h>
#include <stdio.h>

#include "mtracks_string.h"
#include "mtracks_stdlib.h"

#include "mtracks_sqlite.h"

#ifdef _WIN32
#define HOMEDIR_ENV ("UserProfile")
#define DIRSEP ('\\')
#else
#define HOMEDIR_ENV ("HOME")
#define DIRSEP ('/')
#endif

#define DEFAULT_DB_NAME (".mtracks.db")

static char *get_default_db_path(void);

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
  }

  free(the_dbpath);
  the_dbpath = NULL;

  return (dbconn);
}
