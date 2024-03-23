/*Los coeficientes binomiales (n, k) se pueden computar como 
(n,k) = n! / k!*(n - k) escribir una función que los calcule.*/

#include <stdio.h>
#define N   5
#define K   2

int coef_binomials(unsigned int n, unsigned int k);
unsigned long factorial(unsigned char num);

int main(void){

    printf("(%d, %d) = %d\n", N,  K,  coef_binomials(N,K));

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