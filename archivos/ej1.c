/*
Escriba un programa que guarde todo lo que el usuario escriba mientras no escriba 
una cadena centinela pasada como argumento:

$ ./editor texto.txt "hasta la victoria"
*** Guardaré todo lo que escribas en el archivo: texto.txt ***
*** Para terminar, el centinela es: hasta la victoria      ***
Ayer te vi que subías
por el camino a la fuente
dime dónde vas, morena
dime dónde vas, salada.
hasta la victoria
*** Hasta acá llegamos ***

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 100

int main(int argc, char const *argv[]){
    if(argc != 2){
        fprintf(stderr,"ERROR en los argumentos ./programa <nameFile.txt>\n");
        return EXIT_FAILURE;
    }

    char name_file[BUFFER];
    strcpy(name_file,argv[1]);

    FILE* archivo = fopen(name_file,"w");
    if(archivo==NULL){
        perror("ERROR no se pudo abrir el archivo");
        return EXIT_FAILURE;
    }

    char centinela[] = "hasta la victoria";
    char aux[BUFFER];

    printf("*** Guardaré todo lo que escribas en el archivo: texto.txt ***\n");
    printf("*** Para terminar, el centinela es: %s***\n",centinela);

    while(fgets(aux,BUFFER,stdin)){
        if(!strncmp(centinela,aux,strlen(centinela)))
            break;
        fprintf(archivo,"%s",aux);
    }

    puts("*** Hasta acá llegamos ***");

    fclose(archivo);

    return EXIT_SUCCESS;
}



