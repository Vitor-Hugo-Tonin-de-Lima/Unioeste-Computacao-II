#include <stdio.h>

void p1(int *vetor){
	for(int i=0;i<5;i++){
		printf("Digite o valor %d:\n", i);
		scanf("%d",&vetor[i]);
	}
}

int produtoEscalar(int *va, int *vb){
	int resultado;
	
	printf("Preencha o vetor A: \n");
	p1(va);
	
	printf("Preencha o vetor B: \n");
	p1(vb);
	
	resultado = 0;
	for(int i=0;i<5;i++){
		resultado += va[i] * vb[i];
	}
	
	return resultado;
}

int main(){
	
	int va[5], vb[5], resultado;
	
	resultado = produtoEscalar(va, vb);
	
	printf("O produto escalar e: %d", resultado);
	
	return 0;
}