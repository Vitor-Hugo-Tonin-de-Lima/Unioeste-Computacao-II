#include <stdio.h>
#include <ctype.h>

char * filtro(char *S1){
    static char S2[200];
    for(int i=0;i<200;i++){
        if(isalnum(S1[i]) != 0){
            S2[i] = S1[i];
        } else if(S1[i] == '\n'){
            break;
        } else{
           S2[i] = '_'; 
        }
    }

    return S2;
}

int main(){
    char S1[200], *S2;

    printf("Digite o texto: ");
    fgets(S1, sizeof(S1), stdin);

    S2 = filtro(S1);

    printf("%s", S2);

    return 0;
}

