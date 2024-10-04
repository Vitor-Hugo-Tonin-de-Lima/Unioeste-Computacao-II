#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados{
	double variacaoPosicao;
	int tempo;
};

typedef struct Dados Dados;

struct Celula{
	Dados dados;
	struct Celula *pProximo;
};

typedef struct Celula Celula;

struct ListaEncadeada{
	Celula *pPrimeiro;
	Celula *pUltimo;
	int tamanho;
};

typedef struct ListaEncadeada ListaEncadeada;

void inicializar(ListaEncadeada **pLista){
	*pLista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
	(**pLista).pPrimeiro = NULL;
	(**pLista).pUltimo = NULL;
	(**pLista).tamanho = 0;
}

void adicionarFinal(Dados dados, ListaEncadeada *lista){
	
	Celula *novaCelula = (Celula*)malloc(sizeof(Celula));
	novaCelula->dados = dados;
	
	if(lista->tamanho == 0){
		lista->pPrimeiro = novaCelula;
		lista->pUltimo = novaCelula;	
	}else{
		lista->pUltimo->pProximo = novaCelula;
		lista->pUltimo = novaCelula;
	}
	lista->tamanho++;
}

void imprimirLista(ListaEncadeada *lista){
	double auxiliarDouble;
	double maiorValor = 0;
	int auxiliarInt;
	int tempoMaiorValor = 0;
	
	printf("\n------------------------------------------------------------\n");
	Celula *temporario = lista->pPrimeiro;
	while(temporario != lista->pUltimo){
		auxiliarInt = temporario->dados.tempo;
		auxiliarDouble = temporario->dados.variacaoPosicao;
		
		if(auxiliarDouble > maiorValor){
			maiorValor = auxiliarDouble;
			tempoMaiorValor = auxiliarInt;
		}
		
		if(auxiliarInt < 10){
			printf("Tempo %d,  ", auxiliarInt);
		}else{
			printf("Tempo %d, ", auxiliarInt);
		}
		printf("Variacao: %.6lf\n", auxiliarDouble);
		
		temporario = temporario->pProximo;
	}
	printf("Tempo %d, variacao: %lf\n", auxiliarInt+1, auxiliarDouble);
	
	printf("------------------------------------------------------------\n");
	printf("\nO maior valor de variacao ocorreu no tempo %d: %.6lf", tempoMaiorValor, maiorValor);
	printf("\n\n------------------------------------------------------------\n");
}

void limparLista(ListaEncadeada *lista){
	Celula *pCabeca = lista->pPrimeiro;
	while(pCabeca != NULL){
		Celula *temp = pCabeca;
		pCabeca = pCabeca->pProximo;
		free(temp);
	}
	free(lista);
}

int main(){
	ListaEncadeada *lista;
	Dados dados;
	int tempo = 1;
	double valor1, valor2;
	
	inicializar(&lista);
	
	FILE *arquivo = fopen("acelerometro.csv","r");
	if(arquivo == NULL){
		perror("Nao foi possivel abrir o arquivo.");
		return 1;
	}else{
		while(fscanf(arquivo, "%lf;%lf", &valor1, &valor2) == 2){
			dados.variacaoPosicao = ((valor1 - valor2)*100)/valor2;
			dados.tempo = tempo;
			tempo++;
			
			adicionarFinal(dados, lista);
		}
	}
	
	imprimirLista(lista);
	
	fclose(arquivo);
	
	limparLista(lista);
	
	return 0;
}

