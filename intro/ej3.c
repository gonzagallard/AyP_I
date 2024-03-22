/*Escribir una función que convierta un valor en grados Celsius a grados Fahrenheit*/

#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1
#define MIN_TEMP -273.15

float in_data(void);
bool data_invalid(float data);
float celcius_to_Fahrenheit(float celcius);


int main(void){
    float celcius = 0;

    printf("ingrese la cantidad de C a convertir:\t");
    if(data_invalid(celcius = in_data()))
        return EXIT_FAIL;
 
    printf("%.3f C son %.3f F\nFIN PROGRAMA\n",celcius, celcius_to_Fahrenheit(celcius));

    return EXIT_SUCCESS;
}

float in_data(void){
    float data;
    scanf("%f", &data);
    return data;
}

bool data_invalid(float data){
    if(data < MIN_TEMP){
        printf("Datos invalidos\nCERRANDO PROGRAMA\n");
        return true;
    }
    return false;
}

float celcius_to_Fahrenheit(float celcius){
 return (float)9/5*celcius + 32;
}
