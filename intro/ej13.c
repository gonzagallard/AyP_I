/*Escribir un programa que imprima la tabla de multiplicar del número 7*/

#include <stdio.h>
#define NUMERO 7

void tabla_multiplicar(int n);

int main(void){
    tabla_multiplicar(NUMERO);
    return 0;   
}

void tabla_multiplicar(int n){
    for(size_t i = 1; i <= 10; i++){
        printf("%d x %ld = %ld\n", n, i, n*i);
    }
}