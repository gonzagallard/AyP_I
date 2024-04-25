/*
Escribir ciclos que realicen cada una de las siguientes operaciones:

Inicializar un vector de 10 elementos con ceros.

Sumar 1 a cada uno de los 15 elementos del arreglo vector.

Leer del teclado y almacenar 12 valores de punto flotante en el arreglo temp_mensuales.

Imprimir los 5 primeros valores del vector de enteros puntajes en forma de columna.

Sumar un 30% a cada uno de los 20 elementos del arreglo de números salarios.

*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 50


int main(void){
    int vector[10] = {0};
    size_t i;
    for(i=0; i<10 ;i++){
        vector[i]++;
    }  
    
    float temp_mensuales[12];
    char aux[MAX];

    for(i=0 ; i<12 ;i++){
        fgets(aux,MAX,stdin);
        temp_mensuales[i] = atoi(aux);
    }

    int puntajes[6]={1,2,3,4,5};
    for(i=0 ; i<5 ; i++){
        printf("%d\n",puntajes[i]);
    }

    float salarios[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    for(i=0 ; i<20 ; i++){
        salarios[i] += salarios[i]*0.3;
    }
    for(i=0 ; i<10 ; i++){
        printf("%.2f\t",salarios[i]);
    }
    putchar('\n');

    return 0;
}
