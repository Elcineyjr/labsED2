#include <stdio.h>
#include <stdlib.h>

int calc(void) {
    // Implemente essa funcao para resolver a questao 1.
    int pilha[50];
    int top = 0;
    int num;

    char c;
    while( (c = getc(stdin)) != EOF ){ //le char da entrada
        if( c == ' ') continue;
        if( c == '*'){ //se eh mutiplicacao
            int mult = pilha[top-2] * pilha[top-1];
            pilha[top-2] = mult;
            top--;
        }else if( c == '+'){ //se eh adicao
            int adic = pilha[top-2] + pilha[top-1];
            pilha[top-2] = adic;
            top--;
        }else{ //se eh numero
            ungetc(c, stdin);
            scanf("%d", &num);
            pilha[top] = num;
            top++;
        }
    } 
    
    return pilha[0];
}

int main() {
    // Le a entrada e calcula e retorna o resultado.
    int res = calc();
    // Exibe a saida.
    printf("%d\n", res);
}
