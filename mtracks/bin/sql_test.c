#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mtracks_sqlite.h"
#include "receipt.h"
#include "tracksql.h"

int main(void)
{
  int sql_errno = SQLITE_ERROR;
  receipt_t receipt;
  sqlite3 *dbconn = db_connect(NULL);

  if (dbconn) {
    printf("DB connection successful\n");
    strncpy(receipt.date, "2012-07-28", sizeof (receipt.date));
    receipt.amount = 20.01;
    strncpy(receipt.vendor, "Moose", sizeof (receipt.vendor));
    if ((sql_errno = db_add_vendor(dbconn, "Moose", "Computers"))
        != SQLITE_OK) {
      fprintf(stderr, "Failed to insert values into vendors table.\n");
    } else if ((sql_errno = db_add_receipt(dbconn, receipt)) != SQLITE_OK) {
      fprintf(stderr, "Failed to insert values into receipts table.\n");
    } else if ((sql_errno = sqlite3_close(dbconn)) != SQLITE_OK) {
      fprintf(stderr, "Failed to tidy up database connection (%s)\n",
              mtracks_sqlite_strerror(sql_errno));
    }
  }

  return !(sql_errno == SQLITE_OK);
}
