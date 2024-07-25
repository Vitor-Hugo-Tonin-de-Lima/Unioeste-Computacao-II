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

void p4(double *v1, double *v2){
	double v[8];
	p1(v, 8);
	
	for(int i=0;i<8;i++){
		if(v[i] < 0){
			v1[i] = v[i];
		} else{
			v2[i] = v[i];
		}
	}
}

int main(){
	double vetor1[8], vetor2[8];
	int qtd;
	
	p4(vetor1, vetor2);
	
	printf("Digite o numero de elementos a serem impressos: \n");
	scanf("%d", &qtd);
	
	printf("Impressao dos valores do vetor1:\n");
	p3(vetor1, qtd);
	
	printf("Impressao dos valores do vetor2:\n");
	p3(vetor2, qtd);
	
	return 0;
}