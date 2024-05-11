/*
1. En computación es frecuente almacenar números decimales según el formato BCD, en el cual cada dígito entre 0 y 9 se
    almacena utilizando 4 bits.
    En un uint32_t pueden almacenarse 8 dígitos BCD metiendo uno en cada nibble.
    Implementar una función int bcd_a_numero(uint32_t bcd); que reciba un número bcd y devuelva su representación
    numérica. Por ejemplo, si se recibiera el valor 0x12345678 se deberá devolver 12345678.

2. Se tiene un vector de enteros representado sobre una estructura que contiene un puntero a entero que representa el
    vector y un size_t que representa su longitud.
        a. Declarar la estructura en cuestión.
        b. Redefinir la estructura como un tipo vector_t.
        c. Implementar la función vector_t *vector_clonar(const vector_t *v); que reciba un vector v y lo duplique
        en memoria nueva

3. El Departamento de Química nos pide implementar una función int *leer_notas(size_t *n); que lea de stdin
notas válidas (entre 0 y 100) y las almacene en un arreglo. La función debe devolver el arreglo por el nombre y la
cantidad de notas leídas por la interfaz a través del puntero n

*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MASK_8U_DIGIT 0x0F
#define MAX_LINE 100

int diez_expN(int n){
    int valor = 1;
    for(size_t i = 0 ; i < n ; i++){
        valor *= 10;
    }
    return valor;
}

int bcd_a_numero(uint32_t bcd){
    uint32_t aux;
    int numero = 0;
    for(size_t i = 0 ; i < 8 ; i++){
        aux = (bcd & (MASK_8U_DIGIT << (i*4)));
        numero += (aux >> (i*4)) * diez_expN(i);
    }
    return numero;
}

struct vector {
    int *vector;
    size_t longitud;
};

typedef struct vector vector_t;

vector_t *vector_clonar(const vector_t *v){
    vector_t *copia = malloc(1 * sizeof(vector_t));
    if(copia == NULL)
        return NULL;
    
    copia->longitud = v->longitud;

    int *vecCopia = malloc(copia->longitud * sizeof(int));
    if(vecCopia == NULL){
        free(copia);
        return NULL;
    }
    copia->vector = vecCopia;
    for(size_t i = 0; i < copia->longitud ; i++){
        copia->vector[i] = v->vector[i];
    }
    return copia;
}

int *leer_notas(size_t *n){
    int *arreglo = malloc(1 * sizeof(int));
    if(arreglo == NULL)
        return NULL;

    char aux_in[MAX_LINE];
    int nota;
    size_t nNotas = 0;
    bool notaValida = true;
    while(notaValida){
        printf("ingrese una nota(0 - 100):\t");
        fgets(aux_in, MAX_LINE, stdin);
        nota = atoi(aux_in);
        if(nota < 0 || nota > 100){
            notaValida = false;
            continue;
        }
        arreglo[nNotas++] = nota;
        int *aux = realloc(arreglo, (nNotas+1) * sizeof(int));
        if(aux == NULL){
            free(arreglo);
            return NULL;
        }
        arreglo = aux;
    }
    *n = nNotas;
    return arreglo;
}


int main(void){
    uint32_t registro = 0x12345678;
    int numero = bcd_a_numero(registro);
    printf("Numero\t%d\n",numero);

    int vecAux[] = {1,2,3,4,5,6,7};
    
    vector_t vectorA = {
        .vector = vecAux,
        .longitud = 7,
    };
    
    vector_t *vectorB = vector_clonar(&vectorA);

    for(size_t i = 0; i < vectorB->longitud; i++){
        printf("%d\t",vectorB->vector[i]);
    }
    puts("");
    free(vectorB);

    size_t nNotas = 0;
    int *notas = leer_notas(&nNotas);

    for(size_t i = 0; i < nNotas ; i++){
        printf("%d\t",notas[i]);
    }
    printf("\nnotas en total:\t%ld",nNotas);
    puts("");
    free(notas);
    

    return 0;
}
