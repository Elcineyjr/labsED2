#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bst.h"
#define cleber 100

int main(){
    /******** programa cliente do TAD BST ********/

    //numeros de elementos a serem gerados
    int tamanho;
    printf("numero n de elementos a serem inseridos: \n");
    scanf("%d", &tamanho);

    //arv vazia
    Arv* teste = cria_vazia();

    //gera numeros aleatorios 
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++){
        int r = rand() % cleber;
        printf("aleatorio %d \n", r);


        teste  = insere(teste, r); 
    }

    imprime(teste);
    destroi(teste);
    return 0;
}