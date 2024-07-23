#include <stdio.h>

#define M 10

void carregaConjunto(double *vetor){
    int j, i;
    for(i=0;i<M;i++){
        scanf("%lf",&vetor[i]);
        
        j = 0;
        for(j=0;j<i;j++){
            if(vetor[i] == vetor[j]){
                printf("O valor %lf ja esta presente no conjunto, tente novamente.\n", vetor[i]);
                i--;
            }
        }
    }
}

void diferenca(double *X, double *Y, double *D, int *quantidadeElementos){
    int naoIgual;
    for(int i=0;i<M;i++){
        naoIgual = 1;
        for(int j=0;j<M;j++){
            if(X[i] == Y[j]){
                naoIgual = 0;
                break;
            }
        }
        
        if(naoIgual){
            D[*quantidadeElementos] = X[i];
            (*quantidadeElementos)++;
        }
    }
}

void imprimeConjunto(double *vetor, int quantidadeElementos){
    if (vetor[0] != 0){
        printf("D = [");
        for(int i=0;i<quantidadeElementos-1;i++){
            printf("%lf, ",vetor[i]);
        }
        printf("%lf]", vetor[quantidadeElementos]);
    }
}

int main(){
    double X[M], Y[M], D[M];
    static int quantidadeElementos = 0;
    
    printf("Digite os valores do vetor X:\n");
    carregaConjunto(X);
    
    printf("Digite os valores do vetor Y:\n");
    carregaConjunto(Y);
    
    diferenca(X, Y, D, &quantidadeElementos);
    
    printf("O resultado da operacao X / Y esta a seguir: \n");

    imprimeConjunto(D, quantidadeElementos);
    
    return 0;
}
