#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "normal_bst.h"


int main(){
    BST* bst;
    srand(time(NULL));

    int N = 3;
    for(int i = 0; i < N;i++)
        insert(bst, rand());

    // print(bst);
    // destroy(bst);

    return 0;
}