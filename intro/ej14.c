/**Escribir un programa que imprima la tabla de multiplicar para los números del 1 al 10.*/

#include <stdio.h>

int main(void){
    for(size_t i = 1; i <= 10; i++){
        for(size_t j = 1; j <= 10; j++){
            printf("%ld x %ld = %ld\n", i, j, i*j);
        }
        printf("\n");
    }

    return 0;
}