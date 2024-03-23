/*Escribir una función que reciba un número entero y 
devuelva 1 si el número es positivo y 0 si el número es negativo.*/

#include <stdio.h>
#define A 10

int signo(int a);

int main(void){

    printf("A = %d \n", A);
    if (A == 0)
        printf("A es cero\n");  
    if(signo(A) == 1)
        printf("A es positivo\n");
    if(signo(A) == 0)
        printf("A es negativo\n");
    
    return 0;
}

int signo(int a){
    if(a > 0)
        return 1;
    else
        return 0;
}