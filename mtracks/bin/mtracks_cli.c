#include <unistd.h>
#include "mtracks_cli.h"

mtracks_opts_t mtracks_getopt(int argc, char *argv[])
{
  int opt = -1;
  mtracks_opts_t rtn = mtracks_no_type; 

  while ((opt = getopt(argc, argv, MTRACKS_OPTS)) != -1) {
    switch (opt) {
    case 'r':
      rtn = mtracks_add_receipt;
      break;
    case 'V':
      rtn = mtracks_add_vendor;
      break;
    case 'v':
      rtn = mtracks_print_version;
      break;
    case 'h':
      rtn = mtracks_print_help;
      break;
    default:
      rtn = mtracks_no_type;
      break;
    }
  }

  return rtn;
}
