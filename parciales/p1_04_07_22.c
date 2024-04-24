/*
1.  a. Escribir una función
        bool extraer_columna_csv(const char csv[], char sep, size_t ncol, char col[]);
    que dada una cadena de caracteres csv que representa una línea CSV separada por sep y un número de
    columna ncol guarde en la cadena col la columna que corresponda a ese número.

    La función devuelve true en caso de funcionar bien, false en caso de falla.

    Ejemplo, si se llama a la función con "papas|2kg|55.75" como csv, '|' como sep y 1 como col deberá
devolver "2kg".

    Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias deben ser
implementadas.
    b. Dar un mínimo ejemplo de invocación de la función

    2. a. Escribir una función combinar_filas que reciba una matriz de flotantes de tamaño N×M, dos índices y
un multiplicador flotante. La función debe sumarle a la fila indicada por el primer índice los elementos
de la fila indicada por el segundo índice multiplicados por el multiplicador.

b. Teniendo #define N 3 y #define M 3 escribir un pequeño ejemplo de código que declare y defina una
matriz, y llame a la función del punto anterior.

    3. Escribir un programa que cuente la cantidad de caracteres blancos ingresados por stdin. Al detectar que no
hay más datos a ser leídos se deberá imprimir la cantidad. (Nota: para determinar si un carácter es blanco
puede utilizarse la función int isspace(int); de la biblioteca <ctype.h>.)

*/


#include <stdio.h>
#include <stdbool.h>
#define MAX 100
#define N   3
#define M   3


bool extraer_columna_csv(const char csv[], char sep, size_t ncol, char col[]){
    size_t i, act_col;
    for(i = 0, act_col = 0 ; csv[i] != '\0' ; i++ ){
        if(act_col == ncol)
            break;
        if(csv[i] == sep)
            act_col++;
    }
    if(csv[i] == '\0')
        return false;

    for(size_t j = 0 ; csv[i] != '\0' && csv[i] != sep; j++, i++){
        col[j] = csv[i];
    }
    col[i] = '\0';
    return true;
}


void combinar_filas(size_t n, size_t m, float matriz[n][m], size_t fil_1, size_t fil_2, float mult){
    float vec1[MAX] = {0}, vec2[MAX] = {0};
    for(size_t i = 0; i<n ; i++){
        if(i == (fil_1 -1)){
            for(size_t j = 0 ; j<m ;j++)
                vec1[j] = matriz[i][j];
        }
        if(i == (fil_2 - 1)){
            for(size_t j = 0 ; j<m ;j++)
                vec2[j]=mult*matriz[i][j];
        }
    }

    for(size_t i = 0; i<n ;i++){
        if(i == (fil_1 - 1))
            for(size_t j = 0; j<m ;j++)
                matriz[i][j] = vec1[j] + vec2[j];
    }
}





int main(void){
    char ejemplo[MAX] = "papas|2kg|55.75";
    char aux[MAX];
    if(extraer_columna_csv(ejemplo,'|',3,aux))
        puts(aux);
    else
        puts("No se pudo");

    float matriz[N][M] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };
    combinar_filas(N,M,matriz,1,2,2);

    for(size_t i=0; i<N; i++){
        for(size_t j=0; j<M; j++)
            printf("%.2f\t",matriz[i][j]);
        putchar('\n');
    }


    return 0;
}


