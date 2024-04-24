/*Escribir una función es_primo que dado un
número entero devuelva true si el mismo es primo y false en caso contrario.*/



#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool es_primo(int num){
    if(num==0 || num==1)
        return false;
    
    for(size_t i=2; i < sqrt(num) ;i++){
        if(!(num%i))
            return false;
    }

    return true;

}

int main(void){
    int num = 20;
    printf("El numer %s\n", es_primo(num)? "es primo" : "NO es primo");

    return 0;
}
