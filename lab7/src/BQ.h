#ifndef BQ_H
#define BQ_H

#include "item.h"

typedef struct bq BQ;

BQ* BQ_create();
void BQ_destroy(BQ*);
void BQ_print(BQ*);
void BQ_insert(BQ*, Item);
Item BQ_delmax(BQ*);
void BQ_join(BQ*, BQ*);

#endif
