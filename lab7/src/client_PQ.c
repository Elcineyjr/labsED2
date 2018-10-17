#include <stdio.h>
#include "PQ.h"

#define N 10

Item in[N] = {4, 8, 6, 3, 1, 7, 9, 2, 0, 5};

int main(void) {
    PQ_init(N);
    for (int i = 0; i < N; i++) {
        PQ_insert(in[i]);
    }
    PQ_print();
    printf("MAX: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", PQ_delmax());
    }
    printf("\n");
    PQ_finish();
}

