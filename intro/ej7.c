/*Escribir una función que dado un número entero devuelva 1 si el mismo es impar y 0 si fuera par*/

#include <stdio.h>
#define NUM 3

char is_odd(int num);

int main(void){
    if(is_odd(NUM))
        printf("El número %d es impar\n", NUM);
    else
        printf("El número %d es par\n", NUM);
    return 0;
}

char is_odd(int num){
    if(num % 2)
        return 1;
    else
        return 0;
}