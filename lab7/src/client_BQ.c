#include <stdio.h>
#include "BQ.h"

#define N 10

Item in[N] = {4, 8, 6, 3, 1, 7, 9, 2, 0, 5};

int main(void) {
    printf("INPUT:");
    BQ *pq = BQ_create();
    for (int i = 0; i < N; i++) {
        printf(" %d", in[i]);
        BQ_insert(pq, in[i]);
    }
    printf("\nAFTER INPUT - ");
    BQ_print(pq);
    for (int i = 0; i < N; i++) {
        printf("REM. MAX: %d - ", BQ_delmax(pq));
        BQ_print(pq);
    }
    BQ_destroy(pq);
}

