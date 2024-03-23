/*Escribir funciones que calculen:
Factorial
Numero de euler
Exponencial
producto Wallis
Tetracion
*/

#include <stdio.h>
#include <math.h>

#define A   2
#define N   5
#define ERROR 15

unsigned long factorial(unsigned char num);
double num_euler(void);
double exponential_e(double n);
double product_wallis(void);
double tetracion(unsigned char  n, double num);

int main(void){

    printf("Factorial de %d! = %ld\n",  A,  factorial(A));
    printf("Numero de e = %.15lf\n",   num_euler());
    printf("Exponencial de e^%d es = %f\n", A, exponential_e(A));
    printf("El producto wallis da = %f\n",    product_wallis());
    printf("Tetracion de %d ^ %d = %.3f\n",   N,  A,  tetracion(N,A));

    return 0;
}

unsigned long factorial(unsigned char num){
    unsigned long fac = 1;
    for(size_t i = 2; i <= num; i++)
        fac *= i;
    return fac;
}

double num_euler(void){
    double euler = 1.0;
    for(size_t i = 1 ; i <= ERROR ; i++)
        euler += 1.0/factorial(i);
    
    return euler;
}

double exponential_e(double n){
    double e = num_euler();
    return pow(e, n);
}

double product_wallis(void){
    double wallis = 1.0;
    for(size_t i = 1 ; i <= 10000000 ; i++)
        wallis *= (4.0 * i * i) / ((2 * i - 1)*(2 * i + 1));
    
    return wallis;
}

double tetracion(unsigned char n, double num){
    double aux = num;
    if(n == 0)
        return num;

    for(size_t i = 1 ; i <= n ; i++)
        aux = pow(aux, num);
    
    return aux;
}




