#include <stdio.h>

void carregaVetor(double *vetor){
	for(int i=0;i<10;i++){
		printf("Digite o valor do elemento %d:\n", i+1);
		scanf("%lf", &vetor[i]);	
	}
}

void maioresValores(double *vetor){
	double valor1 = 0;
	double valor2 = 0;
	
	for(int i=0;i<10;i++){
		if(vetor[i] > valor1){
			valor1 = vetor[i];
		}
	}
	
	for(int i=0;i<10;i++){
		if(vetor[i] > valor2 && vetor[i] != valor1){
			valor2 = vetor[i];
		}
	}
	
	printf("Os maiores valores sao: %lf e %lf", valor1, valor2);
}

int main(){
	double vetor[10];
	
	carregaVetor(vetor);
	
	maioresValores(vetor);
	
	return 0;
}