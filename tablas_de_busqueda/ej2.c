/*
La clasificación espectral 1 de estrellas (cuerpos celestes) permite agruparlas 
en función de su temperatura, como se muestra en la tabla siguiente
Clase           Temperatura         Color
O             28000 - 50000 K       Azul
B              9600 - 28000 K       Blanco azulado
A               7100 - 9600 K       Blanco
F               5700 - 7100 K       Blanco amarillento
G               4600 - 5700 K       Amarillo
K               3200 - 4600 K       Naranja
M               1700 - 3200 K       Rojo

Defina el tipo enumerativo espectral_t con los símbolos correspondientes a las clases espectrales.

Escriba un programa que le pida al usuario la temperatura de un cuerpo celeste 
y almacene la clase del mismo en una variable del tipo espectral_t. Luego, imprima el color de la estrella.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARR 50
#define MAX_NUM_CLASS 7
#define MSG_ERR_INVALID_TEMP "ERROR, Temperatura no valida\n"

typedef enum{O,B,A,F,G,K,M}espectral_t;
const char color_class[][MAX_ARR]={
    [O] = "Azul",
    [B] = "Blanco azulado",
    [A] = "Blanco",
    [F] = "Blanco amarillento",
    [G] = "Amarillo",
    [K] = "Naranja",
    [M] = "Rojo",
};

int main(void){
    char data[MAX_ARR];
    int data_int;
    espectral_t clase;
    fgets(data,MAX_ARR,stdin);

    data_int = atoi(data);
    if(data_int < 1700 || data_int > 50000){
        fprintf(stderr,MSG_ERR_INVALID_TEMP);
        return 1;
    };

    if(data_int >= 1700 && data_int <= 3200)
        clase = M;
    if(data_int > 3200 && data_int <= 4600)
        clase = K;
    if(data_int > 4600 && data_int <= 5700)
        clase = G;
    if(data_int > 5700 && data_int <= 7100)
        clase = F;
    if(data_int > 7100 && data_int <= 9600)
        clase = A;
    if(data_int > 9600 && data_int <= 28000)
        clase = B;
    if(data_int > 28000 && data_int <= 50000)
        clase = O;

    printf("El color de la estrella es: %s\n",color_class[clase]);

    return 0;
}