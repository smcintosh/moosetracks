#include "mtracks_receipt.h"
#include "mtracks_string.h"
#include <stdio.h>

int add_receipt(void)
{
  int rtn = 1;
  char buf[BUFSIZ];
  char *datestr = NULL;
  char *amountstr = NULL;
  char *vendorstr = NULL;

  memset(buf, '\0', sizeof (buf));

  printf("  Enter purchase date (YYYY-MM-DD): ");
  if (fgets(buf, sizeof (buf), stdin) == NULL) {
    goto out;
  }

  /* TODO validate string */
  datestr = xstrdup(buf);
  memset(buf, '\0', sizeof (buf));
  
  printf("  Enter amount: ");
  if (fgets(buf, sizeof (buf), stdin) == NULL) {
    goto out;
  }

  /* TODO validate string */
  amountstr = xstrdup(buf);
  memset(buf, '\0', sizeof (buf));

  printf("  Enter vendor name: ");
  if (fgets(buf, sizeof (buf), stdin) == NULL) {
    goto out;
  }

  /* TODO validate string */
  vendorstr = xstrdup(buf);

out:
  return (rtn);
}
