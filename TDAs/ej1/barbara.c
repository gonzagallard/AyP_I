#include "alan.h"
#include <stdio.h>



void print_puntos(punto_t *p){
    double valueX = punto_get_x(p);
    double valueY = punto_get_y(p);
    printf("x: %.3f\ty: %.3f\n",valueX,valueY);
}

void cambiar_puntos(punto_t *p, double newX, double newY){
    punto_set_x(p,newX);
    punto_set_y(p,newY);
}

void print_distancia(punto_t *A, punto_t *B){
    printf("La distancia entre A y B es:\t%.3f\n",punto_distancia(A,B));
}

void printNorma(punto_t *p){
    printf("La norma del punto es:\t%.3f\n",punto_norma(p));
}

int main(void){

    punto_t *puntA = punto_crear(2,3);
    print_puntos(puntA);
    punto_t *puntB = punto_crear(0,0);
    print_puntos(puntB);

    punto_copiar(puntB, puntA);
    print_puntos(puntB);

    punto_t *puntAA = punto_clonar(puntA);
    print_puntos(puntAA);

    cambiar_puntos(puntAA, 5, 6);
    print_puntos(puntAA);

    punto_t *puntC = punto_crear(1,1);

    print_distancia(puntAA,puntC);

    printNorma(puntC);

    punto_destruir(puntA);
    punto_destruir(puntAA);
    punto_destruir(puntB);
    punto_destruir(puntC);
    return 0;
}