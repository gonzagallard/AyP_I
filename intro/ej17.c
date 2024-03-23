/*El algoritmo babilonio para calcular la raíz cuadrada de un número n
 consta de los siguientes pasos:
1. Se propone que el resultado de la raíz x vale un valor arbitrario, por ejemplo n
2. Se inicializa y en 1
3. Mientras que la diferencia entre x e y sea superior a nuestro margen de error: 
    El nuevo de x se calcula como el promedio entre x e y
    el nuevo valor de y se calcula como n/x
implementar una funcion que calcule la raiz cuadrada de n segun este metodo*/

#include <stdio.h>
#define ERROR   0.001   
#define RAIZ    5.0

double sqrt_of(double n);

int main(void){
    printf("La raiz de %.3f es : %.3f\n", RAIZ ,sqrt_of(RAIZ));
    return 0;
}

double sqrt_of(double n){
    double x = n, y = 1;
    while(1){
        if((x - y) < ERROR)
            return x;
        x = (x + y)/2;
        y = n / x;
    }
}