
void fix_up(Item *a, int k);

void fix_down(Item *a, int sz, int k);

void print_array(Item *a, int lo, int hi, int k) {
    for (int i = lo; i <= hi; i++) {
        printf("%d", a[i]);
        if (i == k) printf("|");
        else        printf(" ");
    }
    printf("\n");
}

void sort(Item *a, int lo, int hi) {
    int N = hi - lo + 1;
    for (int i = lo; i <= hi; i++)
        fix_up(a, i);    // "Top-down" heap construction.
    while (N > 1) { // Sort down.
        exch(a[1], a[N]);
        fix_down(a, --N, 1);
    }
}
