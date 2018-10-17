void fix_down(Item *a, int sz, int k);

void sort(Item *a, int lo, int hi) {
    int N = hi - lo + 1;
    for (int k = N/2; k >= 1; k--)
        fix_down(a, N, k); // "Bottom-up" heap construction.
    while (N > 1) { // Sort down.
        exch(a[1], a[N]);
        fix_down(a, --N, 1); }
}
