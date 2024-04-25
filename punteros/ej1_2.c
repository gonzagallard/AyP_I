/*
Dadas las definiciones de las variables en la siguiente porción de código 
¿qué espera ver por pantalla utilizando los printf() a continuación? Explique la salida.
*/
#include <stdio.h>

int main(void){
    float * pfloat, manzana = 40.0, pera = 35.0;

    printf("&pfloat: %p\n", &pfloat);// Direccion del puntero
    printf("&manzana: %p\n", &manzana);//Direccion de la variable manzana
    printf("&pera: %p\n", &pera);//direccion de la variable pera

    printf("pfloat: %p\n", pfloat);//direccion donde apunta pfloat (no apuntaa nada ahora)

    pfloat = &manzana;
    printf("pfloat: %p\n", pfloat);//direccion de manzana apuntado por pfloat
    printf("*pfloat: %p\n", *pfloat);//el contenido de manzan apuntado por pfloat

    pfloat = &pera;
    printf("pfloat: %p\n", pfloat);//direccion de pera apuntado por pfloat
    printf("*pfloat: %p\n", *pfloat);//contenido de pera apuntado por pfloat

    int i = 3, * pint;
    float f = 10.0;

    pint = &i;
    *pint = 10; 
    *pint = f;  // incorrecta el puntero contiene tipo int y el contenido de float
    pint = &f;  // incorrecto el puntero apunta a tipo int la direccion es tipo float
    pint = 4321; // incorrecto el puntero apunta a tipo int y la direccion es de una direccion fija

    return 0;
}