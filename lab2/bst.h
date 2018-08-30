#ifndef BST_H
#define BST_H

typedef struct arv Arv;

Arv* cria_vazia();

Arv* cria(int info);

//nao havera insersao de numeros iguais inicialmente
Arv* insere(Arv* arvore, int info);

void destroi(Arv* arvore);

void imprime(Arv* arvore);

#endif //BST_H