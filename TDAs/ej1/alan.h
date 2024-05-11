#ifndef ALAN_H
#define ALAN_H

typedef struct punto punto_t;

punto_t * punto_crear(double, double);  //creador

void punto_destruir(punto_t *); //destructor

//primitivas

punto_t * punto_copiar(punto_t *, const punto_t *);

punto_t * punto_clonar(const punto_t *);

double punto_get_x(const punto_t *);    //getter

double punto_get_y(const punto_t *);    //getter

double punto_set_x(punto_t *, double); //setter

double punto_set_y(punto_t *, double);  //setter

punto_t * punto_sumar(punto_t *, const punto_t *);

punto_t * punto_restar(punto_t *, const punto_t *);

double punto_distancia(const punto_t *, const punto_t *);   //gertter

double punto_norma(const punto_t *);    //getter

#endif

