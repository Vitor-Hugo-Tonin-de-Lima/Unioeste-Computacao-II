#include <stdio.h>
#include <stdlib.h>

#define ARQUIVO "Arquivo_de_texto_legal.txt"

void limpaArquivo(FILE *arquivo){
	int c;
	while((c = fgetc(arquivo)) != '\n' && c != EOF);
}

void p1(char nomeArquivo[255]){
	FILE *arquivo = fopen(nomeArquivo, "w");
	char texto[255];
	
	printf("Digite o texto a ser inserido no arquivo: \n");
	fgets(texto, sizeof(texto), stdin);
	fprintf(arquivo, texto);
	
	fclose(arquivo);
}

void p2(char nomeArquivo[255]){
	FILE *arquivo = fopen(nomeArquivo, "r");
	char texto[255];
	
	fgets(texto,sizeof(texto),arquivo);
	printf("%s", texto);
	
	limpaArquivo(arquivo);
	
	fclose(arquivo);
}

int main(){
	
	p1(ARQUIVO);
	
	p2(ARQUIVO);
	
	return 0;
}