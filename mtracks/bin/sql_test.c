#include "tracksql.h"
#include "mtracks_sqlite.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int sql_errno = SQLITE_OK;
  sqlite3 *dbconn = db_connect(NULL);

  if (dbconn) {
    printf("DB connection successful\n");
    if ((sql_errno = db_add_vendor(dbconn, "Moose", "Computers"))
        != SQLITE_OK) {
      fprintf(stderr, "Failed to insert values into vendors table.\n");
      return 1;
    }
    if ((sql_errno = sqlite3_close(dbconn)) != SQLITE_OK) {
      fprintf(stderr, "Failed to tidy up database connection (%s)\n",
              mtracks_sqlite_strerror(sql_errno));
      return 1;
    }
  } else {
    return 1;
  }

  return 0;
}
