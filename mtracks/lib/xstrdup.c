#include "mtracks_string.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Duplicate a string. Quit the program if there is insufficient memory.
 * @param str The string to duplicate.
 * @return The duplicated string.
 */
char *xstrdup(const char *str)
{
  char *rtn = strdup(str);

  if (!rtn) {
    fprintf(stderr, "ERROR: Out of memory.\n");
    exit(1);
  }

  return (rtn);
}
