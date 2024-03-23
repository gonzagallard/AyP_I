/*Escribir un programa que imprima la tabla de conversión de Celsius 
a Fahrenheit para los valores de 0ºC a 100ºC de 10 en 10 con 2 decimales.*/

#include <stdio.h>
#define INICIO 14.52f
#define FIN 98.47f
#define PASO 10

void print_celcius_to_Fahr_table(float start, float end, int step);
float celcius_to_Fahrenheit(float celcius);

int main(void){
    print_celcius_to_Fahr_table(INICIO, FIN, PASO);
    return 0;
}

float celcius_to_Fahrenheit(float celcius){
    return (float)9/5*celcius + 32;
}

void print_celcius_to_Fahr_table(float start, float end, int step){
    for(float i = start; i <= end; i += step){
        printf("%.2fºC = %.2fºF\n", i, celcius_to_Fahrenheit(i));
    }
}