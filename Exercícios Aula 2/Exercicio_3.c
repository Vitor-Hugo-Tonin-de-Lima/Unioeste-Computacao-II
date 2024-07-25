#include <stdio.h>

void p1(int *vetor){
	for(int i=0;i<5;i++){
		printf("Digite o valor %d:\n", i);
		scanf("%d",&vetor[i]);
	}
}

int * copiaVetor(int *v1){
	static int v2[5];
	
	for(int i=0;i<5;i++){
		v2[i] = v1[i];
	}
	
	return v2;
}

void p3(int *v2, int qtd){
	
	printf("[");
	for(int i=0;i<qtd-1;i++){
		printf("%d, ", v2[i]);
	}
	printf("%d]",v2[qtd-1]);
}

int main(){
	int vetor1[5], qtd;
	int *vetor2;
	
	p1(vetor1);
	
	vetor2 = copiaVetor(vetor1);
	
	printf("Digite o numero de elementos a serem impressos: \n");
	scanf("%d", &qtd);
	
	p3(vetor2, qtd);
	
	return 0;
}