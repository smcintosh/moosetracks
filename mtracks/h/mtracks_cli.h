#ifndef MTRACKS_CLI_H
#define MTRACKS_CLI_H

#define MTRACKS_OPTS ("hrVv")

typedef enum mtracks_opts_e {
  mtracks_no_type,
  mtracks_add_receipt,
  mtracks_add_vendor,
  mtracks_print_version,
  mtracks_print_help
} mtracks_opts_t;

mtracks_opts_t mtracks_getopt(int argc, char *argv[]);

#endif /* MTRACKS_CLI_H */
