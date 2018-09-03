#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct arv {
    int info;
    Arv* esq;
    Arv* dir;
};

Arv* cria_vazia(){
    return NULL;
}

Arv* cria(int info){
    Arv* novo = (Arv*)malloc(sizeof(Arv));
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

//nao havera insersao de numeros iguais 
Arv* insere(Arv* arvore, int info){
    if(!arvore){
        arvore = cria(info);
        printf("criou %d \n", arvore->info);
    }
    else if(info < arvore->info){
        arvore->esq = insere(arvore->esq, info);
        printf("esq\n");
    }
    else if(info > arvore->info){
        arvore->dir = insere(arvore->dir, info); 
        printf("dir\n");
    }
    return arvore;
}

void destroi(Arv* arvore){
    if(!arvore)
        return;
    
    destroi(arvore->esq);
    destroi(arvore->dir);
    free(arvore);
}

void imprime(Arv* arvore){
    if(!arvore)
        return;

    printf("info %d \n", arvore->info);
    imprime(arvore->esq);
    imprime(arvore->dir);
}