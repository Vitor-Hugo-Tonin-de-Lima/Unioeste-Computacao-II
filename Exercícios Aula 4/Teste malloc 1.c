#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int * vetor;
	int tamanho;
	
	printf("Digite o tamanho do vetor a ser criado: ");
	scanf("%d", &tamanho);
	
	vetor = (int *) malloc(tamanho * sizeof(int));
	if(vetor == NULL){
		printf("Erro ao alocar memoria.");
		return 1;
	}
	
	for(int i=0;i<tamanho;i++){
		printf("Digite o valor da posicao [%d]: ", i+1);
		scanf("%d",&vetor[i]);
	}
	
	printf("O vetor e: \n");
	printf("[%d, ", vetor[0]);
	for(int i=1;i<tamanho-1;i++){
		printf("%d, ", vetor[i]);
	}
	printf("%d]", vetor[tamanho-1]);
	
	free(vetor);
	
	printf("O vetor e: \n");
	printf("[%d, ", vetor[0]);
	for(int i=1;i<tamanho-1;i++){
		printf("%d, ", vetor[i]);
	}
	printf("%d]", vetor[tamanho-1]);
	
	return 0;
}