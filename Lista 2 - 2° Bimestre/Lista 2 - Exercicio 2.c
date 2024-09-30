#include <stdio.h>
#include <stdlib.h>

struct Dados{
	double variacao;
	int tempo;
};

typedef struct Dados Dados;

struct Celula{
	Dados dados;
	struct Celula *pProximo;
};

typedef struct Celula Celula;

struct TLista{
	Celula *pPrimeiro;
	Celula *pUltimo;
	int tamanho;
};

typedef struct TLista TLista;

void iniciarLista(TLista **lista){
	*lista = (TLista*)malloc(sizeof(TLista));
	
	(*lista)->pPrimeiro = NULL;
	(*lista)->pUltimo = NULL;
	(*lista)->tamanho = 0;
}

void adicionarFinal(Dados *dados, TLista* lista){
	
	Celula *novaCelula = (Celula*)malloc(sizeof(Celula));
	novaCelula->dados = *dados;
	novaCelula->pProximo = NULL;
	
	if(lista->tamanho == 0){
		lista->pPrimeiro = novaCelula;
		lista->pUltimo = novaCelula;
	}else{
		lista->pUltimo->pProximo = novaCelula;
		lista->pUltimo = novaCelula;
	}
	lista->tamanho++;
}

void imprimirLista(TLista *lista) {
    printf("\n");
    Celula *pCabeca = lista->pPrimeiro;
    while (pCabeca != NULL) {
        printf("[variacao: %lf, tempo: %d]\n", pCabeca->dados.variacao, pCabeca->dados.tempo);
        pCabeca = pCabeca->pProximo;
    }
}

void liberarLista(TLista *lista) {
    Celula *pCabeca = lista->pPrimeiro;
    while (pCabeca != NULL) {
        Celula *temp = pCabeca;
        pCabeca = pCabeca->pProximo;
        free(temp);
    }
    free(lista);
}

int main(){
	TLista *lista;
	Dados dados;
	iniciarLista(&lista);
	int tempo = 1;
	
	FILE *arquivo = fopen("acelerometro.csv","r");
	
	if(arquivo == NULL){
		printf("\nErro na abertura do arquivo.\n");
		return 1;
	}else{
		double valor1, valor2;
		while(fscanf(arquivo, "%lf;%lf", &valor1, &valor2) == 2){
			dados.variacao = ((valor1 - valor2)*100)/valor2;
			dados.tempo = tempo;
			tempo++;
			
			adicionarFinal(&dados, lista);
		}
	
	fclose(arquivo);
	}
	
	if (lista->tamanho == 0) {
        printf("Nenhum dado foi adicionado a lista.\n");
    } else {
        imprimirLista(lista);
    }
    
    liberarLista(lista);
	
	return 0;
}