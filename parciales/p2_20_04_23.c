/*
1. Implementar una función bool misma_cantidad(uint32_t n); que devuelva true si la cantidad de bits
prendidos en las posiciones impares de n es la misma que la de bits prendidos en las posiciones pares.
Por ejemplo, misma_cantidad(0100 1011) -> true porque están prendidos los bits 0, 1, 3 y 6; y dos de
ellos están en posiciones pares y dos en impares.

2. Se quiere implementar una función char *join(char *cadenas[], size_t n, char separador); que
reciba un arreglo de n cadenas de caracteres y devuelva una única cadena que contenga a todas ellas con el
separador intercalado.
Por ejemplo, join({"Hola", "que", "tal"}, 3, ' ') -> "Hola que tal".

3. Se tiene una estructura que representa a una carta de baraja española. La misma contiene el valor de la carta,
que es un número entre 1 y 12, y el palo, que es un enumerativo con las etiquetas ORO, ESPADA, BASTO y COPA.
    >Declarar el enumerativo enum palo y la estructura struct carta.
    >Redefinir struct carta como carta_t.
    >Teniendo ya implementada una función carta_t *sacar_carta_del_mazo(); que al ser llamada devuelve una nueva carta implementar la función:
        carta_t **tirar_reyes(size_t *n);
        que llame a sacar_carta_del_mazo() la cantidad de veces que haga falta hasta obtener un rey (valor 12).
        Debe devolver un arreglo con cada una de las cartas sacadas hasta el momento (incluyendo el rey).
        Se debe devolver, además, la cantidad de cartas sacadas en n
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MASK_8U_FB 0x01U

bool misma_cantidadGonza(uint32_t n){
    int npar, nimpar;
    npar = nimpar = 0;

    for(size_t i = 0 ; i < 32 ; i++){
        if(n & (MASK_8U_FB << i) && !(i%2))
            npar++;
        if(n & (MASK_8U_FB << i) && i%2)
            nimpar++;
    }
    return npar == nimpar;
}

// EJ1

bool misma_cantidad(uint32_t n) {
    int pares = 0;
    for(size_t i = 0; i < 32; i+=2)
        if((1 << i) & n)
            pares++;

    int impares = 0;
    for(size_t i = 1; i < 32; i+=2)
        if((1 << i) & n)
            impares++;

    return pares == impares;
}
//////

char *joinGonza(char *cadena[], size_t n, char separador){
    size_t largo = strlen(cadena[0]);
    char *aux = malloc((largo + 1) * sizeof(char)); 
    if(aux == NULL)
        return NULL;

    strcpy(aux, cadena[0]);
    char sepStr[2] = {separador, '\0'}; // cadena de caracteres que contiene el separador y un carácter nulo


    char *aux2 = NULL; 
    for(size_t i = 1 ; i < n ; i++){
        largo += strlen(cadena[i]) + 1; // +1 for the separator
        aux2 = realloc(aux, (largo + 1) * sizeof(char)); // +1 for the null terminator
        if(aux2 == NULL){
            free(aux);
            return NULL;
        }else{
            aux = aux2;
            strcat(aux, sepStr);
            strcat(aux, cadena[i]);
        }
    }

    return aux;
}

// EJ2
/*
char *join(char *cadenas[], size_t n, char separador) {
    size_t longitud = 0;
    for(size_t i = 0; i < n; i++)
        longitud += strlen(cadenas[i]);

    char *s = malloc((longitud + n) * sizeof(char));
    if(s == NULL) return NULL;
    s[0] = '\0';

    for(size_t i = 0; i < n; i++) {
        strcat(s, cadenas[i]);
        if(i != n) {
            size_t ultimo = strlen(s);
            s[ultimo] = separador;
            s[ultimo + 1] = '\0';
        }
    }

    return s;
}
*/
///////

// EJ3

// a)
enum palos {ORO, COPA, ESPADA, BASTO};

struct carta {
    int valor;
    enum palos palo;
};

// b)
typedef struct carta carta_t;

// c)
carta_t *sacar_carta_del_mazo();

carta_t **tirar_reyes(size_t *n) {
    carta_t **v = NULL;
    *n = 0;

    carta_t *c;
    do {
        c = sacar_carta_del_mazo();
        if(c == NULL) return v; // PodrÃ­a ahorrarme este chequeo.

        carta_t **aux = realloc(v, (*n + 1) * sizeof(carta_t*));
        if(aux == NULL)
            // No sÃ© si sacar_carta_del_mazo() devuelve cartas con dimÃ¡nica o no,
            // entonces en vez de ponerme a liberar devuelvo lo que tengo.
            return v;
        v = aux;

        v[(*n)++] = c;
    } while(c->valor != 12);

    return v;
}
// Esta es una posible implementaciÃ³n, poco realista, mazo infinito aleatorio
carta_t *sacar_carta_del_mazo() {
    carta_t *c = malloc(sizeof(carta_t));
    if(c == NULL) return NULL;
    c->palo = rand() % 4;
    c->valor = rand() % 12 + 1;
    return c;
}


int main(void){
    uint32_t registro = 0x0F005F4BU;

    if(misma_cantidadGonza(registro))
        puts("Igual cantidad");
    else
        puts("No es la misma cantidad");
    
    if(misma_cantidad(registro))
        puts("Igual cantidad");
    else
        puts("No es la misma cantidad");

    int n = 3;
    char separador = '#';
    char *cadenas[] = {"Hola", "com", "va"};
    char *cadSola = NULL;
    cadSola = joinGonza(cadenas,n,separador);

    puts(cadSola);
    printf("largo\t%ld\n",strlen(cadSola));

    free(cadSola);

       // EJ3
    /*
    char *palos[] = {"oro", "copa", "espada", "basto"};
    size_t n;
    carta_t **cartas = tirar_reyes(&n);
    for(size_t i = 0; i < n; i++)
        printf("%d %s\n", cartas[i]->valor, palos[cartas[i]->palo]);

    for(size_t i = 0; i < n; i++)
        free(cartas[i]);
    free(cartas);
    */

    return 0;
}