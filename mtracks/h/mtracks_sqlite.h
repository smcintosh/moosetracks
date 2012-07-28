#ifndef MTRACKS_SQLITE_H
#define MTRACKS_SQLITE_H

#include <sqlite3.h>

char *mtracks_sqlite_strerror(int);
int execute_one_step_statement(sqlite3 *, const char *);

#endif /* MTRACKS_SQLITE_H */
