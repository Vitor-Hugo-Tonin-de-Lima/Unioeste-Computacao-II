#include <stdio.h>

double * p1(){
	static double temperaturas[7];
	
	for(int i=0;i<7;i++){
		printf("Digite o valor %d:\n", i+1);
		scanf("%lf",&temperaturas[i]);
	}
	
	double media, temperaturasAcimaMedia[7];
	
	media = 0;
	for(int i=0;i<7;i++){
		media += temperaturas[i];
	}
	
	media = media / 7.0;
	
	int contador = 0;
	for(int i=0;i<7;i++){
		if(temperaturas[i] >= media){
			temperaturasAcimaMedia[contador] = temperaturas[i];
			contador++;
		}
	}
	
	return temperaturasAcimaMedia;
}

void p3(double *v2, int qtd){
	printf("[");
	for(int i=0;i<qtd-1;i++){
		printf("%lf, ", v2[i]);
	}
	printf("%lf]\n",v2[qtd-1]);
}

int main(){

	double *temperaturasAcima;
	
	temperaturasAcima = p1();
	
	p3(temperaturasAcima, 7);
	
	return 0;
}