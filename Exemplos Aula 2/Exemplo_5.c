#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 2

void getRandom(double r[M][N], int s1, int s2){
    int i,j;

    for(i=0;i<s1;i++){
        for(j=0;j<s2;j++){
            r[i][j] = (double)rand()/(double)RAND_MAX;
            printf("r[%d][%d] = %lf\n", i, j, r[i][j]);
        }
    }
}

int main(){
    double p[M][N];
    int i, j;

    srand( (unsigned)time(NULL));

    getRandom(p, M, N);

    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("r[%d][%d] = %lf\n", i, j, p[i][j]);
        }
    }

    return 0;
}