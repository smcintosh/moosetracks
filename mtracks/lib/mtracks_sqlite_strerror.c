#include "mtracks_sqlite.h"
#include "mtracks_string.h"

/**
 * @brief Translate an SQLite error code into a message.
 * @param(in) sql_errno The SQLite error code to translate.
 * @return A static buffer containing the error code.
 * @remarks Caller must free the returned buffer.
 */
char *mtracks_sqlite_strerror(int sql_errno)
{
  char *message = NULL;

  switch (sql_errno) {
    case SQLITE_OK:
      message = xstrdup("No error detected");
      break;
    case SQLITE_ERROR:
      message = xstrdup("SQL error or missing database");
      break;
    case SQLITE_INTERNAL:
      message = xstrdup("Internal logic error in SQLite");
      break;
    case SQLITE_PERM:
      message = xstrdup("Access permission denied");
      break;
    case SQLITE_ABORT:
      message = xstrdup("Callback routine requested an abort");
      break;
    case SQLITE_BUSY:
      message = xstrdup("The database file is locked");
      break;
    case SQLITE_LOCKED:
      message = xstrdup("A table in the database is locked");
      break;
    case SQLITE_NOMEM:
      message = xstrdup("A malloc() failed");
      break;
    case SQLITE_READONLY:
      message = xstrdup("Attempt to write a readonly database");
      break;
    case SQLITE_INTERRUPT:
      message = xstrdup("Operation terminated by sqlite3_interrupt(");
      break;
    case SQLITE_IOERR:
      message = xstrdup("Some kind of disk I/O error occurred");
      break;
    case SQLITE_CORRUPT:
      message = xstrdup("The database disk image is malformed");
      break;
    case SQLITE_NOTFOUND:
      message = xstrdup("Unknown opcode in sqlite3_file_control()");
      break;
    case SQLITE_FULL:
      message = xstrdup("Insertion failed because database is full");
      break;
    case SQLITE_CANTOPEN:
      message = xstrdup("Unable to open the database file");
      break;
    case SQLITE_PROTOCOL:
      message = xstrdup("Database lock protocol error");
      break;
    case SQLITE_EMPTY:
      message = xstrdup("Database is empty");
      break;
    case SQLITE_SCHEMA:
      message = xstrdup("The database schema changed");
      break;
    case SQLITE_TOOBIG:
      message = xstrdup("String or BLOB exceeds size limit");
      break;
    case SQLITE_CONSTRAINT:
      message = xstrdup("Abort due to constraint violation");
      break;
    case SQLITE_MISMATCH:
      message = xstrdup("Data type mismatch");
      break;
    case SQLITE_MISUSE:
      message = xstrdup("Library used incorrectly");
      break;
    case SQLITE_NOLFS:
      message = xstrdup("Uses OS features not supported on host");
      break;
    case SQLITE_AUTH:
      message = xstrdup("Authorization denied");
      break;
    case SQLITE_FORMAT:
      message = xstrdup("Auxiliary database format error");
      break;
    case SQLITE_RANGE:
      message = xstrdup("2nd parameter to sqlite3_bind out of range");
      break;
    case SQLITE_NOTADB:
      message = xstrdup("File opened that is not a database file");
      break;
    case SQLITE_ROW:
      message = xstrdup("sqlite3_step() has another row ready");
      break;
    case SQLITE_DONE:
      message = xstrdup("sqlite3_step() has finished executing");
      break;
    default:
      message = xstrdup("Unknown SQLite error");
      break;
  }

  return message;
}
