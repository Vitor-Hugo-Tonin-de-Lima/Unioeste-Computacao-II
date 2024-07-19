#include <stdio.h>

void printArray(int *arr, int size){
    int i;

    for(i=0;i<size;i++){
        printf("Elemento arr[%d] e: %d\n", i, arr[i]);
    }
}

void cleanArray(int *arr, int size){
    int i;
    
    for(i=0;i<size;i++){
        arr[i] = 0;
    }
}

int main(){
    int i;
    int foo[5];

    for(i=0;i<5;i++){
        scanf("%d",&foo[i]);
    }

    printf("---------------------------------------------------\n");
    printArray(foo,5);
    cleanArray(foo,5);
    printf("---------------------------------------------------\n");
    printArray(foo,5);

    return 0;
}