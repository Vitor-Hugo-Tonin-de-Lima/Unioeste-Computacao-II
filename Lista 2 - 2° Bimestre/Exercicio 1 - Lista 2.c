#include <stdio.h>
#include <stdlib.h>

void preencher(int **p, int *n){
	int i;
	
	printf("Digite a quantidade de ferramentas: ");
	scanf("%d",n);
	
	*p = (int*)malloc(sizeof(int)*(*n));
	
	for(i=0;i<(*n);i++){
		printf("Digite o numero do patrimonio da %d ferramenta: ", i+1);
		scanf("%d", &(*p)[i]);
	}
}

void imprimir(int *p, int tamanhoPreenchido){
	int i;
	printf("\n");
	for(i=0;i<tamanhoPreenchido;i++){
		printf("Ferramenta %d: %d\n", i+1, p[i]);
	}
}

void desalocar(int *p){
	free(p);
}

int main(){
	int *p;
	int n;
	int tamanhoPreenchido = 0;
	
	preencher(&p, &n);
	
	imprimir(p, n);	
	
	desalocar(p);
	
	return 0;
}