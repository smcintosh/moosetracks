#include <stdio.h>
#include <string.h>

#include "tracksql.h"
#include "mtracks_stdlib.h"

static char *build_vendor_sql_stmt(const char *, const char *);

int db_add_vendor(sqlite3 *dbconn, const char *vendor, const char *category)
{
  /* TODO */
  (void)dbconn;

  int rtn = -1;
  char *stmt = build_vendor_sql_stmt(vendor, category);

  if (!stmt) {
    goto out;
  }
  printf("%s\n", stmt);
  rtn = 0;

out:
  free(stmt);
  stmt = NULL;

  return (rtn);
}

static char *build_vendor_sql_stmt(const char *vendor, const char *category)
{
  const char *stmt = "INSERT INTO vendors VALUES";
  char *buf = xcalloc(1, MTRACKS_STATEMENT_MAX);
  size_t len = strlen(stmt) + strlen(vendor) + strlen(category) + 11;

  if (snprintf(buf, MTRACKS_STATEMENT_MAX,
               "%s ('%s', '%s');", stmt, vendor, category) != (int)len-1) {
    fprintf(stderr, "Failed to populate the SQL buffer for adding a vendor\n");

    free(buf);
    buf = NULL;

    goto out;
  }

out:
  return (buf);
}
