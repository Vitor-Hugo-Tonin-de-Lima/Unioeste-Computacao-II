#include <stdio.h>

void p1(int *vetor){
	for(int i=0;i<5;i++){
		printf("Digite o valor %d:\n", i);
		scanf("%d",&vetor[i]);
	}
}

int main(){
	int vetor[5];
	
	p1(vetor);
	
	printf("[");
	for(int i=0;i<4;i++){
		printf("%d, ",vetor[i]);
	}
	printf("%d]", vetor[4]);
	
	return 0;
}