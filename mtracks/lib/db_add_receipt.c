#include "receipt.h"
#include "tracksql.h"
#include <sqlite3.h>

int db_add_receipt(sqlite3 *db_conn, receipt_t receipt)
{
  (void)db_conn;
  (void)receipt;
  /* Prepare statement */
  /* Execute it */
  /* Destroy statement */

  return (SQLITE_OK);
}
