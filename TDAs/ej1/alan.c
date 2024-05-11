#include "alan.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct punto {
    double x;
    double y;
};

punto_t * punto_crear(double x, double y){
    punto_t *newP = malloc(1 * sizeof(punto_t));
    if(newP == NULL){
        return NULL;
    }
    
    newP->x = x;
    newP->y = y;    

    return newP;
}

void punto_destruir(punto_t *p){
    free(p);
}

punto_t * punto_copiar(punto_t *p1, const punto_t *p2){
    p1->x = p2->x;
    p1->y = p2->y;
    return p1;
}

punto_t * punto_clonar(const punto_t *p){
    punto_t *clonar = malloc(1 * sizeof(punto_t));
    if(clonar == NULL){
        return NULL;
    }
    if(punto_copiar(clonar, p) == NULL){
        free(clonar);
        return NULL;
    }
    return clonar;
}

double punto_get_x(const punto_t *p){
    return p->x;
}
double punto_get_y(const punto_t *p){
    return p->y;
}
double punto_set_x(punto_t *p , double newX){
    p->x = newX;
    return p->x;
}
double punto_set_y(punto_t *p, double newY){
    p->y = newY;
    return p->y;
}
punto_t * punto_sumar(punto_t *p1, const punto_t *p2){
    punto_t *cloneP1 = punto_clonar(p1);
    if(cloneP1 == NULL){
        return NULL;
    }
    p1->x += p2->x;
    p1->y += p2->y;

    return cloneP1;
}

punto_t * punto_restar(punto_t *p1, const punto_t *p2){
    punto_t *cloneP1 = punto_clonar(p1);
    if(cloneP1 == NULL){
        return NULL;
    }
    p1->x -= p2->x;
    p1->y -= p2->y;

    return cloneP1;
}

double punto_distancia(const punto_t *p1, const punto_t *p2){
    return sqrt(pow((p1->x - p2->x),2) + pow((p1->y - p2->y),2));
}

double punto_norma(const punto_t *p){
    return  sqrt((p->x * p->x) + (p->y * p->y));
}

