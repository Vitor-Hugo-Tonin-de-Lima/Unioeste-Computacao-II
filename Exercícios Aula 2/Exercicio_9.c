#include <stdio.h>
	
void bubbleSort(int repeticoes, double *vetor){
	if(repeticoes <= 1){
		return;
	}
	int auxiliar = 0;
	for(int i=0;i<repeticoes;i++){
		if(vetor[i] > vetor[i+1]){
			auxiliar = vetor[i+1];
			vetor[i+1] = vetor[i];
			vetor[i] = auxiliar;
		}
	}
	
	bubbleSort(repeticoes-1, vetor);
}

double * carregaVetor(int *n){
	printf("Digite o numero de termos da funcao: ");
	scanf("%d",n);
	
	static double vetor[100];
	int repeticoes = *n;
	
	for(int i=0;i<repeticoes;i++){
		printf("Digite o valor do elemento %d:\n", i+1);
		scanf("%lf", &vetor[i]);	
	}
	
	bubbleSort(repeticoes, vetor);
	
	return vetor;
}

void p3(double *v2, int qtd){
	printf("[");
	for(int i=0;i<qtd-1;i++){
		printf("%lf, ", v2[i]);
	}
	printf("%lf]\n",v2[qtd-1]);
}

int main(){
	double *vetor;
	int n;
	
	vetor = carregaVetor(&n);
	
	p3(vetor, n);	
	
	return 0;
}