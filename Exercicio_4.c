#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int fatorial(int loop){
    if(loop == 0){
        return 1;
    } else {
        return loop * fatorial(loop-1);
    }
}

double calculaCosseno(double xg, int ng){
    double cosseno;
    int parametro;

    if(ng < 1){
        printf("Digite um valor maior que zero para a aproximacao.");
    } else if(ng == 1){
        cosseno = 1;
    } else{
        cosseno = 1;
        for(int i=1;i<ng;i++){
            parametro = 2 * i;
            cosseno += pow(-1,i) * ((pow(xg,parametro))/(fatorial(parametro)));
        }
    }

    return cosseno;
}

int main(){
    
    double graus, xg, cosseno;
    int ng;

    printf("Digite o valor do angulo do cosseno:\n");
    scanf("%lf", &graus);

    printf("Digite o numero de aproximacao:\n");
    scanf("%d", &ng);

    xg = (graus *  PI) / 180;

    cosseno = calculaCosseno(xg, ng);

    printf("O valor do cosseno e: %lf", cosseno);

    return 0;
}