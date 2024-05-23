/*
Escriba un programa que reciba como argumentos dos números e imprima el resultado de la operación módulo entre ambos.
*/
#include <stdio.h>
#include <stdlib.h>

#define ERROR_FORMAT "ERROR formato: ./program <num1> <num2>"
#define ERROR_DATA   "ERROR EN EL DATO"

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr,"%s\n",ERROR_FORMAT);
        return EXIT_FAILURE;
    }

    char* endptr;
    int value[2];
    
    for(size_t i=1; i<argc; i++){
        value[i-1] = strtol(argv[i],&endptr,10);
        if(endptr == argv[i]){
            fprintf(stderr,"%s:%ld\n",ERROR_DATA,i);
            return EXIT_FAILURE;
        }
        if(*endptr != '\0'){
            fprintf(stderr,"%s:%ld\n",ERROR_DATA,i);
            return EXIT_FAILURE;
        }
    }

    printf("%d %% %d = %d\n",value[0],value[1],value[0]%value[1]);

    return EXIT_SUCCESS; 
}
