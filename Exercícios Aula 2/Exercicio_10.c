#include <stdio.h>

double calculaResistencia(double *vetor, int tamanhoVetor){
	
	for(int i=0;i<tamanhoVetor;i++){
		printf("Digite o valor do elemento %d:\n", i+1);
		scanf("%lf", &vetor[i]);	
	}
	
	double resultado = 0;
	for(int i=0;i<tamanhoVetor;i++){
		resultado += vetor[i];	
	}
	
	return resultado;
}

int main(){
	double vetor[10], resultado;
	int tamanhoVetor;
	
	printf("Digite o numero de elementos: \n");
	scanf("%d", &tamanhoVetor);
	
	resultado = calculaResistencia(vetor, tamanhoVetor);
	
	printf("%lf = ", resultado);
	for(int i=0;i<tamanhoVetor-1;i++){
		printf("%lf + ", vetor[i]);
	}
	printf("%lf", vetor[tamanhoVetor-1]);
	
}