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
    if(!arvore)
        arvore = cria(info);    
    else if(info < arvore->info)
            arvore->esq = insere(arvore->esq, info);
         else if(info > arvore->info)
                 arvore->dir = insere(arvore->dir, info); 

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

// int altura(Arv* arvore){
    //TODO
    
    // if(!arvore)
    //     return -1;
    
    // int alturaEsq = alturaDir = 0;
    // alturaEsq = altura(arvore->esq); 
    // alturaDir = altura(arvore->dir);

    // if(alturaEsq > alturaDir)
    //     return alturaEsq + 1;
    // else return alturaDir + 1;

// }