/*
Escribir las definiciones siguientes:

Un arreglo de enteros con 15 elementos, todos ellos de valor 0.

Un arreglo de 7 doubles, todos ellos de valor 3.0.

Un arreglo de SIZE floats, todos ellos de valor 0.

Un arreglo de 4 enteros con los valores: 9, 5, 1, 1.

Un arreglo de 4 caracteres con los valores: 'h', 'o', 'l', 'a'.

Un arreglo de 4 caracteres con los valores: 104, 111, 108, 97.

Un arreglo con SIZE elementos de algún tipo (bool, int, float, double, etc) y lo inicialice con valores aleatorios.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void print_int(size_t n, int arr[n]){
    for(size_t i=0; i<n ; i++)
        printf("%d ",arr[i]);
    putchar('\n');
}
void print_dbl(size_t n, double arr[n]){
    for(size_t i=0; i<n ; i++)
        printf("%.2f ",arr[i]);
    putchar('\n');
}
void print_fl(size_t n, float arr[n]){
    for(size_t i=0; i<n ; i++)
        printf("%.2f ",arr[i]);
    putchar('\n');
}

void print_char(size_t n, char arr[n]){
    for(size_t i=0; i<n ; i++)
        printf("%c ",arr[i]);
    putchar('\n');
}


int main(void){
    int num1[15] = {0};
    double num2[7] = {3.0,3.0,3.0,3.0,3.0,3.0,3.0};
    float num3[SIZE] = {0};
    int num4[4] = {9,5,1,1};
    char arr1[4] = {'h', 'o', 'l', 'a'};
    char arr2[4] = {104, 111, 108, 97};
    bool arr3[SIZE]={false};

    print_int(15,num1);
    print_int(4,num4);
    print_dbl(7,num2);
    print_fl(SIZE,num3);
    print_char(4,arr1);
    print_char(4,arr2);

    srand(time(NULL));
    size_t i;
    for(i=0; i < SIZE ; i++){
        if(rand()%2)
            arr3[i] = true;
    }
    for(i=0; i < SIZE ; i++){
        printf("%d\t",arr3[i]? 1 : 0);
    }
    putchar('\n');

    return 0;
}