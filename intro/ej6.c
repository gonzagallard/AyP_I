/*Teniendo el radio de un cilindro y su altura escribir funciones que calculen:
El diámetro del cilindro.
La circunferencia.
El área de la base.
El volumen del cilindro.
El área del cilindro.
*/

#include <stdio.h>
#define PI 3.14159265359
#define RADIO 10
#define ALTURA  5

float diametro(float radio);
float circunferencia(float radio);
float area_base(float radio);
float volumen(float radio, float altura);
float area_cilindro(float radio, float altura);

int main(void){
    printf("El diametro del cilindro es: %.2f\n", diametro(RADIO));
    printf("La circunferencia del cilindro es: %.2f\n", circunferencia(RADIO));
    printf("El area de la base del cilindro es: %.2f\n", area_base(RADIO));
    printf("El volumen del cilindro es: %.2f\n", volumen(RADIO, ALTURA));
    printf("El area del cilindro es: %.2f\n", area_cilindro(RADIO, ALTURA));
    return 0;
}

float diametro(float radio){
    return 2 * radio;
}

float circunferencia(float radio){
    return 2 * PI * radio;
}

float area_base(float radio){
    return PI * radio * radio;
}

float volumen(float radio, float altura){
    return area_base(radio) * altura;
}

float area_cilindro(float radio, float altura){
    return 2 * area_base(radio) + circunferencia(radio) * altura;

}








