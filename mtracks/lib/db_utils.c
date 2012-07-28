#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "mtracks_sqlite.h"

/**
 * @brief Given an one-step SQL statement string, prepare and execute it.
 * @param(in) dbconn The SQLite database connection.
 * @param(in) stmt_str The SQL statement string.
 * @return The SQLite error code.
 */
int execute_one_step_statement(sqlite3 *dbconn, const char *stmt_str)
{
  int sql_errno = SQLITE_ERROR;
  sqlite3_stmt *stmt = NULL;
  const char *extra = NULL;

  assert(dbconn && stmt_str);

  if ((sql_errno = sqlite3_prepare_v2(dbconn, stmt_str, strlen(stmt_str),
                                      &stmt, &extra)) != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare SQL statement:\n%s\n", stmt_str);
    fprintf(stderr, "Reason: %s.\n", mtracks_sqlite_strerror(sql_errno));
  } else if (extra && extra[0]) {
    fprintf(stderr, "Unprocessed SQL statement characters:\n%s\n", extra);
    sql_errno = SQLITE_ERROR;
  } else if ((sql_errno = sqlite3_step(stmt)) != SQLITE_DONE) {
    fprintf(stderr, "Failed to process SQL statement:\n%s\n", stmt_str);
    fprintf(stderr, "Reason: %s.\n", mtracks_sqlite_strerror(sql_errno));
  } else if ((sql_errno = sqlite3_finalize(stmt)) != SQLITE_OK) {
    fprintf(stderr, "Failed to finalize SQL statement:\n%s\n", stmt_str);
    fprintf(stderr, "Reason: %s.\n", mtracks_sqlite_strerror(sql_errno));
  }

  return (sql_errno);
}
