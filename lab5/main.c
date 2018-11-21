#include "item.h"
#include <stdio.h>
#include <stdlib.h>

extern void merge_sort(Item *a, Item* aux, int lo, int hi);

Item* init_array(int N){
    Item* array = malloc(N * sizeof(Item));
    return array;
}

int main(int argc, char *argv[]){
    int N = atoi(argv[1]);
    Item* array = init_array(N);

    for(int i = 0; i < N; i++) 
        scanf("%d", &array[i]); 

    Item* aux_array = init_array(N);    
    
    merge_sort(array, aux_array, 0, N-1); 

    for(int j = 0; j < N; j++)
        printf("%d\n", array[j]);

    free(array);

    
    return 0;
}
