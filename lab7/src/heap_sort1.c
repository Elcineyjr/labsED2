#include "PQ.h"

void sort(Item *a, int lo, int hi) {
    int N = hi - lo + 1;
    PQ_init(N);
    for (int i = 0; i < N; i++) {
        PQ_insert(a[i]);
    }
    for (int i = N-1; i >= 0; i--) {
        a[i] = PQ_delmax();
    }
}
