/*Escribir una función que dado un número devuelva el primer número
 múltiplo de 10 inferior a él. Por ejemplo, para 153 debe devolver 150.*/

#include <stdio.h>
#define N 154234

int multipl10(int num);

int main(void){
    printf("El primer número múltiplo de 10 inferior a %d es: %d\n", N, multipl10(N));
    return 0;
}

int multipl10(int num){
    return num - (num % 10);
}