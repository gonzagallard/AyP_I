/*
Resolver los siguientes problemas en forma clara y legible en código ISO-C99

1. a. Escribir una función

    void left_trim(char cadena[]);

    que elimine todos los caracteres de espacio que haya al comienzo de la cadena. Por ejemplo, si se le pasara la
    cadena " hola mundo " después de ejecutar la función la misma deberá ser "hola mundo ".

    No se permite el uso de funciones de biblioteca en este ejercicio. Todo lo necesario debe ser implementado.

    b. Con un pequeño código de ejemplo mostrar cómo utilizar a la función con las cadenas del ejemplo
    anterior.

2. Una matriz cuadrada es triangular superior si todos los elementos debajo de su diagonal principal son iguales
a cero

    a. Escribir una función es_triangular_superior que reciba una matriz de flotantes de tamaño N×N y
    que retorne si es triangular superior o no.

    b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
    la función del punto anterior e imprima un mensaje para el usuario según el resultado.

3. Escribir un programa que le pida un número al usuario y que, de ser posible, le muestre su raíz cuadrada.
(Nota: para calcular una raíz cuadrada puede utilizarse la función double sqrt(double x); de la biblioteca
<math.h>.)

*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CADENA 100
#define N 3


void left_trim(char cadena[]){
    char cadena_aux[MAX_CADENA];
    size_t i;
    for(i = 0 ; cadena[i] == ' ' ; i++);

    size_t j;
    for(j = 0 ; cadena[i] != '\0' ; i++, j++)
        cadena_aux[j] = cadena[i];
    cadena_aux[j] = '\0';

    for(i = 0 ; cadena_aux[i] != '\0' ; i++)
        cadena[i] = cadena_aux[i];
    cadena[i] = '\0';
}
//CORREGIDO_INIT***************************************************************************
size_t _cant_espacios(const char cadena[]){
    size_t i;
    for(i = 0; cadena[i] == ' '; i++);
    return i;
}

void left_trim_CORREGIDO(char cadena[]){
    size_t n = _cant_espacios(cadena);

    size_t i;

    for(i = 0; cadena[i + n] != '\0' ; i++){ // La condicion de corte correcta del for es cadena[i + n] != '\0' y no cadena[i] != '\0'. 
        cadena[i] = cadena[i + n];          //no cambia mucho pero es mas eficiente y consecuente con agregar el '\0' del despues.
    }
    cadena[i] = '\0';
}
//CORREGIDO_FIN***************************************************************************

bool es_triangular_superior(size_t n, float matriz[n][n]){
    for(size_t j = 0 ; j < n ; j++){
        for(size_t i = 0 ; i < n ; i++){
            if(i == j && matriz[i][j] != 1)
                return false;
            if(i > j && matriz[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool es_triangular_superior_CORREGIDO(size_t n, float matriz[n][n]){
    for(size_t i = 1; i < n; i++){
        for(size_t j = 0; j < n && j < i; j++){
            if(matriz[i][j] != 0){
                return false;
            }
        }
    }
    return true;
}


int main(void){
    char ejemplo[MAX_CADENA] = "         hola";
    printf("%s : cadena original\n",ejemplo);
    left_trim(ejemplo);
    printf("%s : cadena recortada\n",ejemplo);

    float matriz[N][N] = {
        {1.0,0 ,3},
        {0  ,1 ,4},
        {0  ,0 ,1},
    };

    if(es_triangular_superior(N,matriz))
        printf("La matriz es triangular superior\n");
    else
        printf("La matriz no es triangular superior\n");
    
    float data_f = 0;
    char data_in[MAX_CADENA];

    printf("ingrese un numero:\t");
    if(fgets(data_in, MAX_CADENA, stdin) == NULL){  //No es necesario verificar 
        fprintf(stderr,"Error en la entrada\n");
        return 1;
    }
    data_f = atof(data_in);
    if(data_f < 0)
        printf("No tiene raiz cuadrada real\n");
    else
        printf("La raiz cuadrada real es: %f\n",sqrt(data_f));

    return 0;
}

