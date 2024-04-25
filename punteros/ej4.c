#include <stdio.h>

int main(void){
    int *ip, **ipp, (*ip16)[16], i, j;
    int matriz[5][16];
    
    ip16 = matriz; //ip16 es un puntero a un arreglo de 16 enteros y matriz es un array bidimensional, un array
                    //de 5 elementos donde cada elemento es un array de 16 enteros. 
                    //ip16 puede recorrer la matriz de la forma     (*ip16 + i)[j]    es algo parecido a int **p     

    ip = (int *)matriz; //no es recomendable castear a punteros, pero la matriz es casteada
                        //a un puntero a entero que apunta al primer elemento de la matriz, el compilador la reconoce como un arreglo de int

    ipp = (int **) matriz;/*NO ES RECOMENDABLE NI SEGURA, matriz es un array de arrays e ipp es un puntero a puntero, se lo usa comunmente 
                            para crear arrays dinamicos de arrays, que no es compatible con un array bidimensional estatico como matriz.    
                            en memoria se ordenan de manera diferente ambos tipos
                        */

    *(*(ip16 + i) + j)  //es la forma correcta para acceder a los datos de un array dinamico de arrays 

    *(*(matriz + i ) + j)//como se trata de un arreglo estatico la forma correcta seria del modo matriz[i][j]

    return 0;
}