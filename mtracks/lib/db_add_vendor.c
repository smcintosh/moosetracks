#include <stdio.h>
#include <string.h>

#include "mtracks_sqlite.h"
#include "mtracks_stdlib.h"
#include "tracksql.h"

int db_add_vendor(sqlite3 *dbconn, const char *vendor, const char *category)
{
  const char *stmt = "INSERT INTO vendors VALUES";
  int sql_errno = SQLITE_ERROR;
  char stmt_str[MTRACKS_STATEMENT_MAX];
  size_t len = strlen(stmt) + strlen(vendor) + strlen(category) + 11;

  memset(stmt_str, '\0', sizeof (stmt_str));

  if (snprintf(stmt_str, MTRACKS_STATEMENT_MAX,
               "%s ('%s', '%s');", stmt, vendor, category) != (int)len-1) {
    fprintf(stderr, "Failed to populate the SQL buffer for adding a vendor\n");
  } else {
    sql_errno = execute_one_step_statement(dbconn, stmt_str);
  }

  return (sql_errno);
}
