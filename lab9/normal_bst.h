#ifndef NORMAL_BST
#define NORMAL_BST


typedef struct bst BST;

BST* create(int info);

void destroy(BST* bst);

BST* insert(BST* bst, int info);

void print(BST* bst);

#endif //NORMAL_BST