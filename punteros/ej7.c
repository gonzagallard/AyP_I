/*
Implementar las siguientes funciones, equivalentes al ejercicio 28 de la guía 1, 
retornando los resultados por la interfaz:

void suma(int a, int b, long int * suma),

void resta(int a, int b, long int * resta),

void producto(int multiplicando, int multiplicador, float * producto),

void division(int dividendo, int divisor, double *), y

mod(): retorna el resto de una división.

*/
#include <stdio.h>

void suma(int a, int b, long int * suma){
    *suma = a + b;
}

void resta(int a, int b, long int * resta){
    *resta = a - b;
}

void producto(int multiplicando, int multiplicador, float * producto){
    *producto = multiplicando * multiplicador;
}

void division(int dividendo, int divisor, double * div){
    *div = dividendo / divisor;
}

void mod(int dividendo, int divisor, int * resto){
    *resto = dividendo - divisor*(dividendo/divisor);
}

int main(void){
    int num = 0, * nmod = &num;
    mod(13,3,nmod);
    printf("resto\t%d\n",*nmod);

    return 0;

}


