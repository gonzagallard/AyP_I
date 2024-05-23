/*
Escriba un programa que imprima por pantalla todos los argumentos recibidos, uno por línea.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    for(size_t i=0; i<argc; i++)
        puts(argv[i]);

    return EXIT_SUCCESS;
}