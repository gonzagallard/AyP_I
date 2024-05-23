/*
Escriba un programa que reciba una cadena de caracteres e imprima su longitud, à la strlen().
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_FORMAT "ERORR el formato es : ./program \"<cadena ingresar>\""

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr,"%s\n",ERROR_FORMAT);
        return EXIT_FAILURE;
    }

    printf("la longitud de la cadena es: %ld\n", strlen(argv[argc-1]));

    return EXIT_SUCCESS;
}