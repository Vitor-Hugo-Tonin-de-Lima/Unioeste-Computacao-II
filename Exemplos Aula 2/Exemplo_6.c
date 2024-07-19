#include <stdio.h>
#include <stdlib.h>

int somaLinha(int *linha, int size){
    int j, soma;

    soma = 0;
    for(j=0;j<size;j++){
        soma += linha[j];
    }

    return soma;
}

int main(){
    int i, j;
    int mfoo[2][2];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&mfoo[i][j]);
        }
    }

    for(i=0;i<2;i++){
        printf("Soma linha %d: ",i);
        printf("%d\n",somaLinha(mfoo[i], 2));
    }

    return 0;
}