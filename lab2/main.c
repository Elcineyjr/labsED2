#include <stdio.h>
#include "bst.h"

int main(){
    Arv* teste = cria(5);
    insere(teste, 6);
    insere(teste, 10);
    insere(teste, 3);
    insere(teste, 7);
    insere(teste, 1);

    imprime(teste);
    destroi(teste);
    return 0;
}