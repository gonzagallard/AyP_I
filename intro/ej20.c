/*La potencia de un binomio se computa como  (x + y)^n = SUM(n,k)*x^(n-k)*y^k
Escribir una función void desarrollar_binomio(int n);   que imprima los términos a calcular. 
Por ejemplo, para desarrollar_binomio(3);    la misma debe imprimir:
(x + y)^3 = + 1.x^3.y^0 + 3.x^2.y^1 + 3.x^1.y^2 + 1.x^0.y^3
*/


#include <stdio.h>
#define GRADO 3

int coef_binomials(unsigned int n, unsigned int k);
unsigned long factorial(unsigned char num);
void desarrollar_binomio(int n);

int main(void){

    desarrollar_binomio(GRADO);

    return 0;
}

unsigned long factorial(unsigned char num){
    unsigned long fac = 1;
    for(size_t i = 2; i <= num; i++)
        fac *= i;
    return fac;
}

int coef_binomials(unsigned int n, unsigned int k){
    return (double)factorial(n) / (factorial(k) * factorial(n - k));
}

void desarrollar_binomio(int grado){

    printf("(x + y)^%d =",grado);
    for(int k = 0 ; k <= grado ; k++){
        printf(" + %d.x^%d.y^%d",coef_binomials(grado,k),grado - k,k);
    }
    puts("\n");
}