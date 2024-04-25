/*
Implementar una función swap que reciba 2 datos a y b por puntero y 
los intercambie, de forma tal que b sea a y viceversa.
*/
#include <stdio.h>


void swap(int *a, int *b){
    int aux;
    aux = *b;
    *b = *a;
    *a = aux;
}


int main(void){
    int a = 1, b = 2;
    swap(&a,&b);
    printf("a: %d\tb:%d\n",a,b);
    
    return 0;
}