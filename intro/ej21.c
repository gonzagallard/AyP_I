/*Escribir una función que dado un número entero lo imprima espejado.
Por ejemplo: 9511 se imprime como 1159. 
Sugerencia: utilice los operadores módulo % y división /.*/

#include <stdio.h>
#define NUM 9511

void print_mirror(int n);

int main(void){

    print_mirror(NUM);

    return 0;
}

void print_mirror(int n){
    int div = n;

    printf("%d  =>  ",NUM);
    
    while(div != 0){
        printf("%d", div % 10);
        div /= 10;
    }
    puts("\n");
}