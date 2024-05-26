/*
Implementá una función que lea una línea (cadena de caracteres) de largo indefinido (de cualquier FILE *) 
y la retorne por el nombre. Implementar otra función que realice lo mismo, 
pero retornando la cadena leída por la interfaz y si todo salió bien por el nombre.
Prototipos:
    char * readline(FILE *);
    bool readline(FILE *, char **);

La función se puede implementar tanto con fgetc() como con fgets(). Hacerlo de ambas maneras.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUFFER 100

char * readline1(FILE *archivo){
    char* leer_linea=malloc(BUFFER*sizeof(char));
    if(leer_linea==NULL) return NULL;
    fgets(leer_linea,BUFFER,archivo);
    return leer_linea;
}
bool readline2(FILE *archivo, char **cad_leida){
    if(cad_leida == NULL)
        return false;

    size_t i=0;
    char aux[BUFFER];
    while((aux[i++]=fgetc(archivo))!= '\n');
    aux[i] = '\0';
    strcpy(*cad_leida,aux);

    return true;
}

int main(){
    FILE* archivo = fopen("test.txt","r");
    if(archivo==NULL){
        perror("ERROR al abrir el archivo");
        return EXIT_FAILURE;
    }

    char* linea_leida=readline1(archivo);
    puts(linea_leida);

    char *linea_leida2 = malloc(BUFFER*sizeof(char));
    if(linea_leida2==NULL){
        perror("ERROR asignacion memoria linea2");
        return EXIT_FAILURE;
    }
    if(readline2(archivo,&linea_leida2)){
        puts(linea_leida2);
    }

    free(linea_leida);
    free(linea_leida2);
    fclose(archivo);

    return EXIT_SUCCESS;
}