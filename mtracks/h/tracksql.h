#ifndef TRACKSQL_H
#define TRACKSQL_H

#include <sqlite3.h>

#include "receipt.h"

/* Arbitrarily chosen maximum length of SQL statements */
#define MTRACKS_STATEMENT_MAX (256)

sqlite3 *db_connect(const char *);
int db_add_vendor(sqlite3 *, const char *, const char *);
int db_add_receipt(sqlite3 *, receipt_t);

#endif /* TRACKSQL_H */
