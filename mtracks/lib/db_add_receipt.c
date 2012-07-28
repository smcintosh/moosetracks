#include <assert.h>
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

#include "mtracks_sqlite.h"
#include "receipt.h"
#include "tracksql.h"

int db_add_receipt(sqlite3 *dbconn, receipt_t receipt)
{
  const char *stmt = "INSERT INTO receipts VALUES";
  int sql_errno = SQLITE_ERROR;
  char stmt_str[MTRACKS_STATEMENT_MAX];

  memset(stmt_str, '\0', sizeof (stmt_str));

  assert(dbconn);

  /* TODO check snprintf() return code */
  snprintf(stmt_str, sizeof (stmt_str), "%s ('%s', %8.2f, '%s');", stmt,
           receipt.date, receipt.amount, receipt.vendor);

  sql_errno = execute_one_step_statement(dbconn, stmt_str);

  return (sql_errno);
}
