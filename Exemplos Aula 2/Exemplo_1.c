#include <stdio.h>

double f(int arr[], int size){
    int i;
    double a;
    double s = 0;

    for(i=0;i<size;i++){
        s += arr[i];
    }

    a = s / size;

    return a;
}

int main(){

    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    avg = f(balance,5);
    printf("Valor medio: %lf", avg);

    return 0;
}