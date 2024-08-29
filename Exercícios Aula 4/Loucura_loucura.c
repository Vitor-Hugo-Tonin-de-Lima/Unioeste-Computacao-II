#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *** tridimensional;
	int limitador;
	int x = 0;
	int y = 0;
	int z = 0;
	int w=1;
	
	printf("Digite o tamanho do limitador: ");
	scanf("%d", &limitador);
	
	tridimensional = (int ***) malloc(limitador * sizeof(int **));
	if(tridimensional == NULL){
		printf("Erro ao alocar memoria.");
		return 1;
	}
	
	for(int i=0;i<limitador;i++){
		tridimensional[i] = (int **) malloc(limitador * sizeof(int *));
		if(tridimensional[i] == NULL){
			printf("Erro ao alocar memoria.");
			return 1;
		}
		
		for(int j=0;j<limitador;j++){
			tridimensional[i][j] = (int *) malloc(limitador * sizeof(int));
			if(tridimensional[i][i] == NULL){
			printf("Erro ao alocar memoria.");
			return 1;
			}
		}
	}

	for(int i=0;i<limitador;i++){
		for(int j=0;j<limitador;j++){
			for(int k=0;k<limitador;k++){
				tridimensional[i][j][k] = i+j+k;
			}
		}
	}
	
	while(w == 1){
		printf("Digite qual posicao deseja imprimir [x, y, z]: \n");
		scanf("%d%d%d", &x, &y, &z);
		
		printf("Posicao em [%d, %d, %d]: %d\n", x, y, z, tridimensional[x][y][z]);	
		
		printf("Digite 1 se quer seguir: \n");
		scanf("%d", &w);
	}
	
	for(int i=0;i<limitador;i++){
		for(int j=0;j<limitador;j++){
			free(tridimensional[i][j]);
		}
		
		free(tridimensional[i]);
	}
	
	free(tridimensional);
	
	return 0;
}
