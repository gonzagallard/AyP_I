/*Escribir una función que convierta un valor en grados Fahrenheit a grados Celsius.
 La fórmula que los relaciona es F = 9/5*C + 32*/

#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1
#define MIN_TEMP -459.67

float in_data(void);
bool data_invalid(float data);
float fahrenheit_to_celcius(float farh);

int main(void){
    float farenh = 0;

    printf("ingrese la cantidad de F a convertir:\t");
    if(data_invalid(farenh = in_data()))
        return EXIT_FAIL;

    printf("%.3f F son %.3f C\nFIN PROGRAMA\n",farenh, fahrenheit_to_celcius(farenh));

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

float fahrenheit_to_celcius(float farh){
 return (5.0/9) * (farh - 32);
}

