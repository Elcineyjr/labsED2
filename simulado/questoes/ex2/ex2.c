#include <stdio.h>
#include <stdlib.h>

int busca_index(int* vet, int num, int tam){
    for(int i =  0; i < tam; i++){
        if(vet[i] == num)
            return i;
    }
    return -1;
}

void print_post_order(int *pre, int *in, int N) {
    // Implemente essa funcao para resolver a questao 2.
    
    int index = busca_index(in, pre[0], N);

    if(index != 0){ // index ==  0 significa q nao tem arv da esq 
        print_post_order(pre+1, in, N);
    }

    if(index != N-1){
        print_post_order(, in ,N);
    }

}

int main() {
    // Le a entrada.
    int N;
    scanf("%d\n", &N);
    int *pre = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &pre[i]);
    }
    int *in = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }

    // Calcula e exibe a saida.
    print_post_order(pre, in, N);
    printf("\n");
    free(pre);
    free(in);
}
