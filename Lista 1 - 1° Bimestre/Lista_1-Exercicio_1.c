#include <stdio.h>
#include <string.h>
#include <strings.h>

struct memoria{
	double quantidade;
	char unidade[2];
};

struct celular{
	char marca[100];
	double preco;
	struct memoria memoria1;
	int peso;
	int numeroChips;
};

void limpaStdin(){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void leituraCelular(struct celular *celular){
	printf("-------------------------------------------------------\n");
	printf("Digite a marca do celular:\n");
	fgets(celular->marca, 100, stdin);
	
	printf("Digite o preco do celular:\n");
	scanf("%lf", &celular->preco);
	
	printf("Digite a quantidade de memoria do celular:\n");
	scanf("%lf", &celular->memoria1.quantidade);
	
	printf("Digite a unidade de memoria do celular: [MB/GB]\n");
	scanf("%s", celular->memoria1.unidade);
	
	printf("Digite o peso do celular em gramas:\n");
	scanf("%d", &celular->peso);
	
	printf("Digite a quantidade de chips do celular:\n");
	scanf("%d", &celular->numeroChips);
	
	limpaStdin();
	printf("-------------------------------------------------------\n");
}

int compara(struct celular *celular1, struct celular *celular2, int cam){
	if(cam == 2){
		if(celular1->preco < celular2->preco){
			return 1;
		} else if(celular2->preco < celular1->preco){
			return 2;
		} else{
			return 3;
		}
	} else if(cam == 3){
		double memoriaCelular1, memoriaCelular2;
		
		memoriaCelular1 = celular1->memoria1.quantidade;
		memoriaCelular2 = celular2->memoria1.quantidade;
		
		if(strcasecmp(celular1->memoria1.unidade,"GB") == 0){
			memoriaCelular1 *= 1000;
		}
		
		if(strcasecmp(celular2->memoria1.unidade,"GB") == 0){
			memoriaCelular2 *= 1000;
		}
		
		if(memoriaCelular1 > memoriaCelular2){
			return 1;
		} else if(memoriaCelular2 > memoriaCelular1){
			return 2;
		} else{
			return 3;
		}
	} else if(cam == 4){
		if(celular1->peso < celular2->peso){
			return 1;
		} else if(celular2->peso < celular1->peso){
			return 2;
		} else{
			return 3;
		}
	} else if(cam == 5){
		if(celular1->numeroChips > celular2->numeroChips){
			return 1;
		} else if(celular2->numeroChips > celular1->numeroChips){
			return 2;
		} else{
			return 3;
		}
	} else{
		return 0;
	}
}

void imprimeCelular(struct celular *celular){
	printf("-------------------------------------------------------\n");
	printf("Dados do celular:\n");
	printf("Marca: %s", celular->marca);
	printf("Preco: %.2lf\n", celular->preco);
	printf("Quantidade de memoria: %.2lf %s\n", celular->memoria1.quantidade, celular->memoria1.unidade);
	printf("Peso: %d\n", celular->peso);
	printf("Quantidade de chips: %d\n", celular->numeroChips);
	printf("-------------------------------------------------------\n");
}

int main(){
	while(1){
		struct celular celular1;
		struct celular celular2;
		int campo, melhorCelular;
		
		printf("Digite os dados do celular 1:\n");
		leituraCelular(&celular1);
		printf("\n");
		
		printf("Digite os dados do celular 2:\n");
		leituraCelular(&celular2);
		printf("\n");
		
		printf("Digite o campo a ser comparado: [2,5]\n");
		scanf("%d", &campo);
		
		melhorCelular = compara(&celular1, &celular2, campo);
		
		if(melhorCelular == 1){
			imprimeCelular(&celular1);
			break;
		} else if(melhorCelular == 2){
			imprimeCelular(&celular2);
			break;
		} else if(melhorCelular == 3){
			imprimeCelular(&celular1);
			printf("\n");
			imprimeCelular(&celular2);
			break;
		} else if(melhorCelular == 0){
			printf("Ocorreu um erro.");
		}
	}
	
	return 0;
}
