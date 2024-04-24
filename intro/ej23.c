/*
23.Escribir una función que dados dos números x e y imprima:
    x es mayor que y, si x es mayor que y,
    x y y son iguales, si los números son iguales.
*/

#include <stdio.h>
#include <stdbool.h>

void es_mayor(int x, int y){
    if(x > y)
        printf("x es mayor que y\n");
    else if(x==y)
        printf("x es igual que y\n");
    else
        printf("x es menor que y\n");
}

int main(void){
    int x = 2, y = 1;
    es_mayor(x,y);
    return 0;
}