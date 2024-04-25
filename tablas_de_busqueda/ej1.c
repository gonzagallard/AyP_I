/*
Defina el tipo enumerativo mes_t con 12 símbolos, uno por cada mes.
 Escriba una porción de código que dada una variable de tipo mes_t, imprima por pantalla el mes correspondiente.
*/
#include <stdio.h>

typedef enum {ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC} mes_t;

int main(void){
    mes_t mes = JUL;

    if(mes == ENE)
        printf("El mes es ENERO\n");
    if(mes == JUL)
        printf("El mes es JULIO\n");
    return 0;
}
