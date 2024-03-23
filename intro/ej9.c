/*Escribí una función que compare (reciba) 2 números enteros a y b. 
La función debe retornar un número menor, igual o mayor que cero si a es, 
respectivamente, menor que, igual a, o mayor que b.*/

#include <stdio.h>
#define A 10
#define B 20

char comparar(int a, int b);

int main(void){
    printf("A = %d, B = %d \n", A, B);
    if(comparar(A, B) == -1)
        printf("A es menor que B\n");
    if(comparar(A, B) == 0)
        printf("A es igual a B\n");
    if(comparar(A, B) == 1)
        printf("A es mayor que B\n");
    return 0;
}

char comparar(int a, int b){
    if(a < b)
        return -1;
    if(a == b)
        return 0;
    else
        return 1;
}
