#include <stdio.h>
#include "mtracks_cli.h"
#include "mtracks_version.h"
#include "mtracks_receipt.h"

static void print_usage(const char *progname, const char *reason);

static void print_usage(const char *progname, const char *reason)
{
  printf("%s: %s", progname, reason);
  printf("USAGE:\n");
  printf("%s -r\n", progname);
  printf("\tAdd a receipt to the database\n");
  printf("%s -V\n", progname);
  printf("\tAdd a vendor to the database\n");
  printf("%s -h\n", progname);
  printf("\tPrint this help message\n");
  printf("%s -v\n", progname);
  printf("\tPrint the program version number\n");
}

int main(int argc, char *argv[])
{
  int rtn_code = 0;
  mtracks_opts_t opt = mtracks_getopt(argc, argv);

  switch (opt) {
  case mtracks_add_receipt:
    rtn_code = add_receipt();
    break;
  case mtracks_add_vendor:
    printf("Add vendor\n");
    break;
  case mtracks_print_version:
    printf("%s\n", get_version_string());
    goto out;
  case mtracks_print_help:
    print_usage(argv[0], "Help!\n");
    goto out;
  case mtracks_no_type:
    print_usage(argv[0], "No operation type detected.\n");
    rtn_code = 1;
    goto out;
  }

out:
  return rtn_code;
}
