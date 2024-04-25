/*
Escribir un programa que imprima cada uno de los elementos de un arreglo dos dimensional 
utilizando un puntero para acceder a los mismos, en lugar de utilizar subíndices. 
Utilizar el siguiente arreglo y los punteros indicados abajo:
    int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
    int * ptr;
    int (*ptr2vector)[4];
    int fila, col;
*/

#include <stdio.h>



int main(void){
    int matriz[3][4] = {{ 1, 2, 3, 4}, { 5, 6, 7, 8}, { 9,10,11,12}};
    int * ptr;
    int (*ptr2vector)[4];
    int fila, col;

    ptr = (int *)matriz;  //Casteo de matriz bidimensional, arreglo de arreglos estatico a un vector con nxm elementos
    for(fila=0 ; fila<12 ; fila++){
            printf("%d\t",*(ptr+fila));
    }
    putchar('\n');

    ptr2vector = matriz;
    for(fila=0 ; fila<3 ; fila++){
        for(col=0 ; col<4 ; col++){
            printf("%d\t",(*ptr2vector+fila)[col]);
        }
    }
    putchar('\n');
    return 0;
}