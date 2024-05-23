/*
Escriba un programa que reciba dos cadenas de caracteres e imprima el resultado de su comparación lexicográfica, 
como lo haría la función strcmp() o strcasecmp().
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR_FORMAT "ERROR el formato es: ./program \"<cadena1>\" \"<cadena2>\""

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr,"%s\n",ERROR_FORMAT);
        return EXIT_FAILURE;
    }

    size_t i;
    for(i=0; argv[2][i] && argv[1][i] == argv[2][i]; i++);
    int value_cmp = argv[1][i] - argv[2][i];
    if(value_cmp < 0)
        printf("Cadena1 es menor que cadena2\n");
    if(value_cmp > 0)
        printf("Cadena1 es Mayor que cadena1\n");
    if(value_cmp == 0)
        printf("Cadena1 es Igual a Cadena2\n");

    return EXIT_SUCCESS;
}