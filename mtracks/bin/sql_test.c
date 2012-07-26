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
    if ((sql_errno = sqlite3_close(dbconn)) != SQLITE_OK) {
      char *message = mtracks_sqlite_strerror(sql_errno);
      fprintf(stderr, "Failed to tidy up database connection (%s)\n", message);
      free(message);
      message = NULL;
      return 1;
    }
  }

  return 0;
}
