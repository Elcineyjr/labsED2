#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "normal_bst.h"

struct bst {
    int info;
    BST* l;
    BST* r;
};


BST* create(int info){
    BST* new = malloc(sizeof(*new));

    new->info = info;
    new->l = NULL;
    new->r = NULL;

    return new;
}

void destroy(BST* bst){
    if(!bst) return;

    destroy(bst->l);
    destroy(bst->r);

    free(bst);
}

int depth(BST* bst){
    if(!bst) return -1;

    int lDepth = depth(bst->l);
    int rDepth = depth(bst->r);
    
    if(lDepth > rDepth)
        return lDepth + 2;
    return rDepth + 2;
}


BST* insert(BST* bst, int info){
    if(!bst) bst = create(info);

    if(info >= bst->info) bst->r = insert(bst->r, info);
    
    if(info < bst->info) bst->l = insert(bst->l, info);
}

void print(BST* bst){
    if(!bst) return;

    printf("%d", bst->info);
    print(bst->l);
    print(bst->r);
}