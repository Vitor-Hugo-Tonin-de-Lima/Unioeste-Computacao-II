#include <stdio.h>

void printMatrix(int arr[2][2], int s1, int s2){
    int i, j;

    printf("Impressao da matriz %dx%d\n", s1, s2);
    for(i=0;i<s1;i++){
        for(j=0;j<s2;j++){
            printf("%d,", arr[i][j]);
        }
        printf("\n");
    }
}

void cleanMatrix(int arr[2][2], int s1, int s2){
    int i, j;

    for(i=0;i<s1;i++){
        for(j=0;j<s2;j++){
            arr[i][j] = 0;
        }
    }

}

int main(){
    int i, j;
    int mfoo[2][2];

    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d", &mfoo[i][j]);
        }
    }

    printf("---------------------------------------------------\n");
    printMatrix(mfoo, 2, 2);
    cleanMatrix(mfoo, 2, 2);
    printf("---------------------------------------------------\n");
    printMatrix(mfoo, 2, 2);
    return 0;
}