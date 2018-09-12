#include <stdio.h>
#include <stdlib.h>

int calc(void) {
    // Implemente essa funcao para resolver a questao 1.
    int resultado;
    int pilha[50];
    int top = 0;

    char c = getc(stdin);
    while(c != EOF ){ //le char da entrada
        if( c == '*'){ //se eh mutiplicacao
            int mult = pilha[top-2] * pilha[top-1];
            pilha[top-2] = mult;
            top--;
        }else if( c == '+'){ //se eh adicao
            int adic = pilha[top-2] * pilha[top-1];
            pilha[top-2] = adic;
            top--;
        }else{ //se eh numero
            ungetc(c, stdin);
            int num;
            scanf("%d", &num);
            pilha[top] = num;
            top++;
        }
        c = getc(stdin);
    } 
    
    return pilha[0];
}

int main() {
    // Le a entrada e calcula e retorna o resultado.
    int res = calc();
    // Exibe a saida.
    printf("%d\n", res);
}
