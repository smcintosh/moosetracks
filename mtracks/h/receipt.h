#ifndef RECEIPT_H
#define RECEIPT_H

/* DATESIZ is strlen('yyyy-mm-dd') = 4+1+2+1+2+1 = 11 */
#define DATESIZ (11)

/* Arbirarily chosen sizes. 30 should be okay, right? */
#define VENDORSIZ (30)
#define CATEGORYSIZ (30)
#define AMOUNTSIZ (8)
#define AMOUNTDEC (2)

typedef struct receipt_s {
  char date[DATESIZ];
  float amount;
  char vendor[VENDORSIZ];
} receipt_t;

#endif /* RECEIPT_H */
