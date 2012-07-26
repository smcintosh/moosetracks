#include "mtracks_sqlite.h"
#include "mtracks_string.h"

static char *Sqlite_err_messages[] = {
  "Successful result", /* SQLITE_OK */
  "SQL error or missing database",  /* SQLITE_ERROR */
  "Internal logic error in SQLite",  /* SQLITE_INTERNAL */
  "Access permission denied",  /* SQLITE_PERM */
  "Callback routine requested an abort",  /* SQLITE_ABORT */
  "The database file is locked",  /* SQLITE_BUSY */
  "A table in the database is locked",  /* SQLITE_LOCKED */
  "A malloc() failed",  /* SQLITE_NOMEM */
  "Attempt to write a readonly database",  /* SQLITE_READONLY */
  "Operation terminated by sqlite3_interrupt()", /* SQLITE_INTERRUPT */
  "Some kind of disk I/O error occurred",  /* SQLITE_IOERR */
  "The database disk image is malformed",  /* SQLITE_CORRUPT */
  "Unknown opcode in sqlite3_file_control()",  /* SQLITE_NOTFOUND */
  "Insertion failed because database is full",  /* SQLITE_FULL */
  "Unable to open the database file",  /* SQLITE_CANTOPEN */
  "Database lock protocol error",  /* SQLITE_PROTOCOL */
  "Database is empty",  /* SQLITE_EMPTY */
  "The database schema changed",  /* SQLITE_SCHEMA */
  "String or BLOB exceeds size limit",  /* SQLITE_TOOBIG */
  "Abort due to constraint violation",  /* SQLITE_CONSTRAINT */
  "Data type mismatch",  /* SQLITE_MISMATCH */
  "Library used incorrectly",  /* SQLITE_MISUSE */
  "Uses OS features not supported on host",  /* SQLITE_NOLFS */
  "Authorization denied",  /* SQLITE_AUTH */
  "Auxiliary database format error",  /* SQLITE_FORMAT */
  "2nd parameter to sqlite3_bind out of range",  /* SQLITE_RANGE */
  "File opened that is not a database file" /* SQLITE_NOTADB */
};

static char *Sqlite_err_messages_100s[] = {
  "sqlite3_step() has another row ready", /* SQLITE_ROW */
  "sqlite3_step() has finished executing" /* SQLITE_DONE */
};

static char *Def_err_message = "Unrecognized SQLite error";

/**
 * @brief Translate an SQLite error code into a message.
 * @param(in) sql_errno The SQLite error code to translate.
 * @return A static buffer containing the error code.
 */
char *mtracks_sqlite_strerror(int sql_errno)
{
  char *message = NULL;

  if (sql_errno < 100) {
    message = Sqlite_err_messages[sql_errno];
  } else if (sql_errno >= 100 && sql_errno < 200) {
    message = Sqlite_err_messages_100s[sql_errno - 100];
  } else {
      message = Def_err_message;
  }

  return message;
}
