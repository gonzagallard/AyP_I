/*Escribir una función que dadas las coordenadas de un vector en
R3 (x,y,z) devuelva la norma del mismo dada por sqrt(x^2 + y^2 + z^2)*/

#include <stdio.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1

float in_data(void);
float norma(float x, float y, float z);

int main(void){
    float data_x, data_y, data_z;
    data_x = data_y = data_z = 0;

    printf("Ingrese cordenada x:\t");
    data_x = in_data();
    printf("Ingrese cordenada y:\t");
    data_y = in_data();
    printf("Ingrese cordenada z:\t");
    data_z = in_data();

    printf("(%.2f, %.2f, %.2f) su norma es %.2f\nFIN PROGRAMA\n"
            ,data_x ,data_y ,data_z ,norma(data_x ,data_y ,data_z));
            
    return EXIT_SUCCESS;
}

float in_data(void){
    float data;
    scanf("%f", &data);
    return data;
}

float norma(float x, float y, float z){
    return sqrt(x*x + y*y + z*z);
}
