#include <stdio.h>

#define N 5

int produtoEscalar(int *vetor1, int *vetor2){
    int resposta = 0;

    for(int i=0;i<N;i++){
        resposta += vetor1[i] * vetor2[i];
    }

    return resposta;
}

int main(){

    int vetor1[N], vetor2[N];

    printf("Digite 5 valores para o vetor 1: \n");
    
    for(int i=0;i<N;i++){
        scanf("%d",&vetor1[i]);
    }

    printf("Digite 5 valores para o vetor 2: \n");
    
    for(int i=0;i<N;i++){
        scanf("%d",&vetor2[i]);
    }

    int produto = produtoEscalar(vetor1, vetor2);

    printf("O resultado do produto escalar e: %d", produto);

    return 0;
}