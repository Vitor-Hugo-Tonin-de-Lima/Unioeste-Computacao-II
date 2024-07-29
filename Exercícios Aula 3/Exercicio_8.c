#include <stdio.h>

int busca(char *A, char *B){
	int condicao;
	
	for(int i=0;i<sizeof(B);i++){
		condicao = 0;
		for(int j=0;j<sizeof(A);j++){
			if(B[i] == A[j]){
				condicao = 1;
				break;
			}
		}
		if(condicao = 0){
			break;
		}
	}
	
	return condicao;
}

int main(){
	int valor;
	
	valor = busca("o mundoooo belo", "mundo");
	printf("%d\n", valor);
	
	valor = busca("o mundoooo belo", "chuva");
	printf("%d\n", valor);
	
	return 0;
}