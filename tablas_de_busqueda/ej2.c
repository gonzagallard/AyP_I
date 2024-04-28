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
#define MSG_ERR_INVALID_TEMP "ERROR, Temperatura no valida\n"

typedef enum{O,B,A,F,G,K,M,CLASS_NUM}espectral_t;
char const*const color_class[CLASS_NUM]={
    [O] = "Azul",
    [B] = "Blanco azulado",
    [A] = "Blanco",
    [F] = "Blanco amarillento",
    [G] = "Amarillo",
    [K] = "Naranja",
    [M] = "Rojo",
};

espectral_t give_class(const int data){
    espectral_t clase;
    if(data >= 1700 && data<= 3200)
        clase = M;
    if(data > 3200 && data<= 4600)
        clase = K;
    if(data > 4600 && data<= 5700)
        clase = G;
    if(data > 5700 && data<= 7100)
        clase = F;
    if(data > 7100 && data<= 9600)
        clase = A;
    if(data > 9600 && data<= 28000)
        clase = B;
    if(data > 28000 && data<= 50000)
        clase = O;
    return clase;
}

const char *name_class(espectral_t class){
    return color_class[class];
}

int main(void){
    char data[MAX_ARR];
    int data_int;
    fgets(data,MAX_ARR,stdin);

    data_int = atoi(data);
    if(data_int < 1700 || data_int > 50000){
        fprintf(stderr,MSG_ERR_INVALID_TEMP);
        return 1;
    };

    espectral_t clase = give_class(data_int);

    printf("El color de la estrella es: %s\n",name_class(clase));

    return 0;
}