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

void p5(){
	double intersecao[10];
	double X[10], Y[10];
	int contador = 0;
	
	printf("Digitando o vetor X:\n");
	p1(X, 10);
	
	printf("Digitando o vetor Y:\n");
	p1(Y, 10);
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(X[i] == Y[j]){
				intersecao[contador] = X[i];
				contador ++;
				break;
			}
		}
	}
	
	p3(intersecao, 10);
}

int main(){

	p5();
	
	return 0;
}