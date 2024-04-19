/*
1. Escribir una función
    void imprimir_numero(int n);
que dado un número n lo imprima por stdout. Este problema debe ser resuelto sin el uso de ninguna
función de biblioteca con excepción de putchar().
Por ejemplo, si la función se invoca como imprimir_numero(9511); la misma debe imprimir por la
pantalla 9511.


2. Un conocido periodista emprendió una cruzada contra el lenguaje inclusivo en el cual considera que
cualquier palabra que contenga el carácter 'e' es un ejemplo de esto y debe ser censurado.

a. Escribir una función es_inclusiva que reciba una cadena de caracteres y que retorne si contiene
alguna letra 'e' o no.

b. Escribir un pequeño ejemplo de código que invoque a la función con alguna cadena e imprima
un mensaje según el resultado.

3. Escribir un programa que le pida al usuario una distancia y un tiempo y que, de ser posible, calcule y
muestre la velocidad asociada.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100



void imprimir_numero(int n){
    int vec[MAX];
    int resto = 0, div = n;
    size_t i;
    for(i = 0 ; div != 0 ; i++){
        resto = div % 10;
        div /= 10;
        
        vec[i] = resto;
    }
    
    for(int j = i - 1; j >= 0 ; j--)
        putchar(vec[j] + '0');
}

// 1
void imprimir_numero1(int n) {
/*    if(n < 0) {
        putchar('-');
        n = -n;
    }*/

    int digitos[20];
    int i;
    for(i = 0; n != 0; i++) {
        digitos[i] = n % 10;
        n /= 10;
    }

    for(; i > 0; i--)
        putchar(digitos[i - 1] + '0');
}

int diez_a_la(int n) {
    int potencia = 1;
    for(int i = 0; i < n; i++)
        potencia *= 10;
    return potencia;
}

void imprimir_numero2(int n) {
    int digitos;
//    int potencia = 1;

    int aux = n;
    for(digitos = 0; aux != 0; digitos++) {
        aux /= 10;
//        potencia *= 10;
    }

    for(int i = 0; i < digitos; i++) {
        putchar((n / diez_a_la(digitos - i - 1)) % 10 + '0');
//      potencia /= 10;
    }
}

// 2.a
bool es_inclusivo(const char s[]) {
    for(size_t i = 0; s[i] != '\0'; i++)
        if(s[i] == 'e')
            return true;
    return false;
}

// 3


int main(void){
      // 1
    imprimir_numero(9511);
    putchar('\n');
    imprimir_numero1(9511);
    putchar('\n');

    // 2.b
/*    if(es_inclusivo("alumnes"))
        puts("Es inclusivo");
    else
        puts("No es inclusivo");
    */
    printf("%ses inclusivo\n", es_inclusivo("alumnes") ? "" : "no ");

    // 3
    char aux[MAX];

    printf("Ingrese una distancia: ");
    fgets(aux, MAX, stdin);
    float distancia = atof(aux);

    printf("Ingrese un tiempo: ");
    fgets(aux, MAX, stdin);
    float tiempo = atof(aux);

    if(tiempo == 0) {
        printf("Tiempo invalido\n");
        return 1;
    }

    printf("La velocidad es %f\n", distancia / tiempo);


    return 0;
}










