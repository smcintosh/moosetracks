#include "mtracks_version.h"
#include "libutil.h"
#include <stdio.h>

static char *Version_string = NULL;

/**
 * @brief Get a globally allocated buffer containing the mtracks version.
 * @return The version string.
 */
char *get_version_string(void)
{
  if (!Version_string) {
    Version_string = xcalloc(18, 1);
    if (snprintf(Version_string, 18, "Moose tracks %s\n", MTRACKS_VERSION)
        != 16) {
      fprintf(stderr,
              "ERROR: Failed to populate an array with the version number.\n");
      free(Version_string);
      Version_string = NULL;
    }
  }

  return (Version_string);
}
