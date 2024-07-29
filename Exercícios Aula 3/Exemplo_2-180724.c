#include <stdio.h>

#define N 5

void EscreveVetor(int *vetor){
    for(int i=0;i<N;i++){
        scanf("%d",&vetor[i]);
    }
}

int *CopiaVetor(int *vetor){
    static int vetorCopia[N];
    
    for(int i=0;i<N;i++){
        vetorCopia[i] = vetor[i];
    }
    
    return vetorCopia;
}

void ImprimirVetor(int *vetor, int numeroElementos){
    
    for(int i=0;i<numeroElementos;i++){
        printf("%d, ", vetor[i]);
    }
}

int main(){

    int vetor1[N], numero;

    printf("Digite 5 valores para o vetor 1: \n");
    EscreveVetor(vetor1);

    int *vetorCopiado = CopiaVetor(vetor1);
    
    printf("Digite quantos valores do vetor deseja imprimir: \n");
    scanf("%d",&numero);
    
    ImprimirVetor(vetorCopiado, numero);
    
    return 0;
}