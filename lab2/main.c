#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"

int main(){
    /******** programa cliente do TAD BST ********/

    //numeros de elementos a serem gerados
    // int tamanho;
    // printf("numero n de elementos a serem inseridos: \n");
    // scanf("%d \n", &tamanho);

    //arv vazia
    Arv* teste = cria_vazia();

    //gera numeros aleatorios *********TODO gera numeros dentro de um intervalo especifico
    srand(time(NULL));
    int r = rand();

    teste  = insere(teste, r); //primeira insersão deve retornar a arvore
    insere(teste, 6);
    insere(teste, 10);
    insere(teste, 3);
    insere(teste, 7);
    insere(teste, 1);

    imprime(teste);
    destroi(teste);
    return 0;
}