#include <stdio.h>

int * p1(){
	static int temperaturas[7];
	
	for(int i=0;i<7;i++){
		printf("Digite o valor %d:\n", i+1);
		scanf("%d",&temperaturas[i]);
	}
	
	return temperaturas;
}

char f(int indice){
	if(indice == 1){
		return 'd';
	} else if(indice == 2){
		return 's';
	} else if(indice == 3){
		return 't';
	} else if(indice == 4){
		return 'q';
	} else if(indice == 5){
		return 'q';
	} else if(indice == 6){
		return 's';
	} else {
		return 's';
	}
}

void p8(char dia, int temperatura){
	printf("%c: ", dia);
	for(int i=0;i<temperatura;i++){
		printf("O");
	}
	printf("\n");
}

int main(){

	int *temperaturas;
	
	temperaturas = p1();
	
	char dia;
	for(int i=0;i<7;i++){
		dia = f(i);
		p8(dia, temperaturas[i]);
	}
	
	return 0;
}