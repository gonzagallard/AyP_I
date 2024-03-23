/*Escribir un programa que imprima, en 3 líneas separadas, su nombre, apellido y padrón.*/

#include <stdio.h>
#define NOMBRE "Tito"
#define APELLIDO "Jerez"
#define PADRON 101231

int main(void){
    printf("Nombre: %s\n", NOMBRE);
    printf("Apellido: %s\n", APELLIDO);
    printf("Padron: %d\n", PADRON);
    return 0;
}
