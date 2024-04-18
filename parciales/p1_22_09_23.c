/*
1. Escribir mensajes de chat es cansador y ni te cuento leerlos después. Se propone un formato para acortar
mensajes consistente en eliminar sus vocales. Por ejemplo, el texto "algoritmos y programacion" puede
resumirse como "lgrtms y prgrmcn".
    a. Implementar una función void abreviar_texto(char nombre[]); que reciba una cadena de caracteres
y la abrevie según este formato. Asumir que la cadena tiene únicamente minúsculas.
    No se permite el uso de funciones de biblioteca en este ejercicio. Todo lo necesario debe ser implementado.
    b. Con un pequeño código mostrar cómo utilizar a la función con la cadena del ejemplo anterior.

2. Se tienen matrices en las que, sin importar el contenido de su primera fila y su primera columna, se quiere
verificar que el resto de sus elementos sean la suma del elemento de arriba y el de la izquierda. Es decir, que
cada    A_ij = A_{i-1, j} + A_{i, j-1}
    a. Escribir una función es_suma que reciba una matriz de flotantes de tamaño N×M y retorne si la misma
cumple con la condición pedida o no.

    b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
la función del punto anterior e imprima un mensaje para el usuario según el resultado.

3. En los partidos de fútbol se juegan dos tiempos de 45 minutos cada uno. En la Argentina un evento en un
partido se registra como el tiempo y los minutos, por ejemplo 39 minutos del 2do tiempo, mientras que
internacionalmente los tiempos se registran como minutos totales, para el ejemplo anterior 84 minutos.

Escribir un programa que le pida al usuario la cantidad de minutos y el tiempo del evento de un partido y
que, de ser posible, le muestre la cantidad de minutos totales.

Realizar todas las validaciones pertinentes.

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100
#define N 3
void abreviar_texto(char nombre[]){
    char vocales[5] = {'a','e','i','o','u'};
    char aux[MAX];
    bool copiar;
    size_t i, j;
    for(i = 0, j = 0 ; nombre[i] != '\0' ; i++){
        copiar = true;
        for(size_t k = 0 ; k < 5 ; k++){
            if(nombre[i] == vocales[k]){
                copiar = false;
                break;
            }
        }

        if(copiar)
            aux[j++] = nombre[i];
        
    }
    aux[j] = '\0';

    for(i = 0 ; aux[i] != '\0' ; i++){
        nombre[i] = aux[i];
    }
    nombre[i] = '\0';
}

//######################################################
bool es_vocal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

/*
bool es_vocal(char c) {
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    for(size_t i = 0; i < 5; i++)
        if(c == vocales[i])
            return true;
    return false;
}*/

void abreviar_texto_CORREGIDO(char texto[]) {
    size_t i = 0;
    size_t j = 0;

    while(texto[j] != '\0') {
   //     if(texto[j] == 'a' || texto[j] == 'e' || texto[j] == 'i')
          if(es_vocal(texto[j]))
            j++;
        else
            texto[i++] = texto[j++];
    }
    texto[i] = '\0';
}
/*
void abreviar_texto(char texto[]) {
    for(size_t i = 0; texto[i] != '\0'; i++) {
        if(es_vocal(texto[i])) {
            for(size_t j = i; texto[j] != '\0'; j++)
                texto[j] = texto[j + 1];
            i--;
        }
    }
}*/
//#############################################################




bool es_suma(size_t n, size_t m, float matriz[n][m]){
    for(size_t i = 1 ; i < n ; i++){
        for(size_t j = 1 ; j < m ; j++){
            if(matriz[i][j] != (matriz[i-1][j]+matriz[i][j-1]))
                return false;
        }
    }

    return true;
}





int main(void){
    char cadena[MAX] = "algoritmos y programacion";
    printf("%s : cadena original\n", cadena);
    abreviar_texto(cadena);
    printf("%s : cadena recortada\n", cadena);

    float matriz[N][N] = {
        {1,2,3},
        {2,4,2},
        {3,7,14},
    };
    if(es_suma(N,N,matriz))
        printf("La matriz cumple\n");
    else
        printf("La matriz NO cumple\n");

    /*
    printf("La matriz %scumple la propiedad\n", es_suma(M, M, m) ? "" : "no");
    */
    
    char data_in[MAX];
    int data_min, data_tiempo;
    printf("ingrese cantidad de minutos:\t");
    if(fgets(data_in,MAX,stdin)==NULL){
        fprintf(stderr,"Error en la entrada\n");
        return 1;
    }
    if((data_min = atoi(data_in)) < 0 || data_min > 45){
        fprintf(stderr,"Error minutos invalidos\n");
        return 1;
    }
    printf("ingrese el tiempo del partido:\t");
    if(fgets(data_in,MAX,stdin)==NULL){
        fprintf(stderr,"Error en la enrtada\n");
        return 1;
    }

    /*
    if(minutos < 0 || minutos > 45 || tiempo <= 0 || tiempo > 2) {
        fprintf(stderr, "Minutos o tiempo incorrectos\n");
        return 1;
    }
    */

    data_tiempo = atoi(data_in);
    if(data_tiempo == 1)
        printf("Tiempo trancurrido total: %d min\n",data_min);
    else if(data_tiempo == 2)
        printf("Tiempo transcurrido total: %d min\n", 45 + data_min);
    else{
        fprintf(stderr,"Error tiempo no valido\n");
        return 1;
    }


    return 0;
}

