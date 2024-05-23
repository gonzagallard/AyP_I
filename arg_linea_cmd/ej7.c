/*
Escriba un programa que imprima de manera ordenada los argumentos recibidos:
    $ ./g07e07 Ser o "no ser," "esa es" "la cuestión"
    Ser
    esa es
    la cuestión
    no ser,
    o

Si el primer parámetro del programa es -r, entonces los ordena al revés:
    $ ./g07e07 Ser o "no ser," "esa es" "la cuestión"
    o
    no ser,
    la cuestión
    esa es
    Ser
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ERROR_FORMAT "ERROR de formato"

int main(int argc, char* argv[]){
    if(argc == 1){
        fprintf(stderr,"%s\n",ERROR_FORMAT);
        return EXIT_FAILURE;
    }
    
    bool reverse = false;
    if(!strcmp(argv[1],"-r")){
        reverse = true;        
    }
    
    int init_arg = 1;
    if(reverse){
        init_arg = 2;
    }

    int vec[argc];
    for(size_t i=0 ; i<argc; i++){
        vec[i] = i;  
    }

    bool swap = false;

    for(size_t i=init_arg ; i<argc-1; i++){
        for(size_t j=i+1; j<argc; j++){
            int value_cmp = strcmp(argv[vec[i]],argv[vec[j]]);
            if(reverse){   
                if(value_cmp < 0)
                    swap = true;
            }else{
                if(value_cmp > 0)
                    swap = true;
            }
            if(swap){
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
            swap = false;
        }
    }

    for(size_t i=init_arg; i<argc; i++){
        puts(argv[vec[i]]);
    }

    return EXIT_SUCCESS;
}
