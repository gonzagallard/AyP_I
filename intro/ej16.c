/*Escribir un programa que imprima por pantalla todas las fichas del dominó, sin repetir.*/

#include <stdio.h>

void print_domino_tiles(void);

int main(void){
    print_domino_tiles();
    return 0;
}

void print_domino_tiles(void){
    for (size_t i = 0; i <= 6; i++){
        for (size_t j = i; j <= 6; j++){
            printf("[%ld|%ld] ", i, j);
        }
        printf("\n");
    }
}