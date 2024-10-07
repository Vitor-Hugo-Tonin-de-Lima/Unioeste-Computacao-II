#include <stdio.h>
#include <stdlib.h>

#define ARQUIVO "Arquivo_de_texto_legal.txt"

void limpaArquivo(FILE *arquivo){
	int c;
	while((c = fgetc(arquivo)) != '\n' && c != EOF);
}

void p1(char nomeArquivo[255], char modo[255]){
	FILE *arquivo = fopen(nomeArquivo, modo);
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo.");
		return;
	}
	char texto[255];
	
	printf("Digite o texto a ser inserido no arquivo: \n");
	fgets(texto, sizeof(texto), stdin);
	fprintf(arquivo, texto);

	fclose(arquivo);
}

void p2(char nomeArquivo[255]){
	FILE *arquivo = fopen(nomeArquivo, "r");
	if(arquivo == NULL){
		printf("Erro ao abrir o arquivo.");
		return;
	}
	
	char texto[255];
	
	printf("\n-------------------------------------------------------\n");
	printf("Impressao do arquivo:\n");
	
	while(fgets(texto,sizeof(texto),arquivo) != NULL){
		printf("%s", texto);
	}
	
	fclose(arquivo);
}

void p3(char nomeArquivo[255]){
	int linhas;
	char texto[255];
	printf("Digite quantas linhas de texto deseja inserir:\n");
	
	scanf("%d", &linhas);
	fgets(texto, sizeof(texto), stdin);
	
	p1(nomeArquivo, "w");
	
	for(int i=0;i<linhas-1;i++){
		p1(nomeArquivo, "a");
	}
}

int main(){
	
	p3(ARQUIVO);
	
	p2(ARQUIVO);
	
	return 0;
}