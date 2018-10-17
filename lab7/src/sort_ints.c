#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define key(A)          (A)
#define less(A, B)      (key(A) < key(B))
#define exch(A, B)      { Item t = A; A = B; B = t; }
#define compexch(A, B)  if (less(B, A)) exch(A, B)

//#include "select_sort.c"
//#include "insert_sort1.c"
//#include "insert_sort2.c"
//#include "shell_sort.c"
//#include "merge_sort1.c"
//#include "merge_sort2.c"
//#include "bu_merge_sort.c"
//#include "quick_sort1.c"
//#include "quick_sort2.c"
//#include "quick_sort3.c"
//#include "it_quick_sort.c"
//#include "heap_sort1.c"
//#include "heap_sort2.c"
#include "heap_sort3.c"

#define N 10

void print(char *msg, Item *a) {
    printf(msg);
//     for (int i = 0; i < N; i++) {
//         printf("%d ", a[i]);
//     }
    for (int i = 1; i <= N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    //Item a[N] = {4, 8, 6, 3, 1, 7, 9, 2, 0, 5};
    Item a[N+1] = {-1, 4, 8, 6, 3, 1, 7, 9, 2, 0, 5};
    print("ORIGINAL: ", a);
    //sort(a, 0, N-1);
    sort(a, 1, N);
    print("SORTED:   ", a);
}
