/*Escribir una función que reciba el capital inicial, 
una tasa de interés y un número de años y devuelva el monto final a cobrar.
La formula a utilizar:  C(n)= c*(1+x/100)^n
Donde c es el capital inicial, x es la tasa de interes y 
n es el numero de anios a calcular.*/

#include <stdio.h>
#define EXIT_SUCCESS 0
#define EXIT_FAIL -1


float in_data(void){
    float data;
    scanf("%f", &data);
    if(data < 0)
        return EXIT_FAIL;
    else 
        return data;
}

float n_natural_power(float base, int n){
    float power = base;

    for(size_t i = 1 ; i < n ; i++)
        power *= base;

    return power;
}


int main(void){
    float init_cap, interest, final_cap;
    int years;
    init_cap = interest = years = final_cap = 0;

    printf("Ingrese el capital inicial:\t");
    if((init_cap=in_data()) <= 0){
        printf("Datos invalidos\nCERRANDO PROGRAMA\n");
        return EXIT_FAIL;
    }

    printf("Ingrese la tasa de interes:\t");
    if((interest = in_data()) <= 0){
        printf("Datos invalidos\nCERRANDO PROGRAMA\n");
        return EXIT_FAIL;
    }
    
    printf("Ingrese los anios:\t");
    if((years = in_data()) <= 0){
        printf("Datos invalidos\nCERRANDO PROGRAMA\n");
        return EXIT_FAIL;
    }

    final_cap = init_cap*n_natural_power(1+interest/100 , years);
    printf("El capital a cobrar es de:\t %.3f \nFIN PROGRAMA\n", final_cap);

    return EXIT_SUCCESS;
}