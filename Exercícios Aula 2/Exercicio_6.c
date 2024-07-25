#include <stdio.h>

void p1(double *vetor, int numeroElementos){
	for(int i=0;i<numeroElementos;i++){
		printf("Digite o valor %d:\n", i);
		scanf("%lf",&vetor[i]);
	}
}

void p3(double *v2, int qtd){
	printf("[");
	for(int i=0;i<qtd-1;i++){
		printf("%lf, ", v2[i]);
	}
	printf("%lf]\n",v2[qtd-1]);
}

void p6(){
	double uniao[20];
	double X[10], Y[10];
	int contador = 0;
	
	printf("Digitando o vetor X:\n");
	p1(X, 10);
	
	printf("Digitando o vetor Y:\n");
	p1(Y, 10);
	
	for(int i=0;i<10;i++){
		uniao[i] = X[i];
		uniao[i+10] = Y[i];
	}
	
	p3(uniao, 20);
}

int main(){

	p6();
	
	return 0;
}