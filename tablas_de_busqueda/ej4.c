/*
Un número de CUIT es un número de 2 + 8 + 1 = 11 dígitos, donde los primeros dos dígitos hasta el año 2021 correspondían al tipo,
 siendo 20 hombre, 27 mujer y 24 para repetidos, los 8 al número de DNI y el último dígito un dígito verificador.

El dígito verificador se calcula como una suma ponderada de los otros 10 dígitos, por ejemplo, si el tipo es mujer y el DNI es 12345678 se computa:

  2 x 5 + 7 x 4 + 1 x 3 + 2 x 2 + 3 x 7 + 4 x 6 + 5 x 5 + 6 x 4 + 7 x 3 + 8 x 2 = 176.

Se calcula el resto de dividir ese número por 11 (en este caso es 0). Si el resto es 0 el dígito verificador es 0. 
Si el resto es mayor a 1 el dígito verificador es 11 - resto. En el caso de que el resto sea 1 entonces el tipo se cambia por 23 y el dígito queda 9 si el tipo era hombre,
 4 si el tipo era mujer y 3 si el tipo era repetido. En el ejemplo la CUIT resultante es 27123456780.

Implementar una función uint64_t generar_cuit(tipo_t tipo, int dni); que dado el enumerativo tipo y el dni genere la CUIT correspondiente.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_DNI 8
#define MAX_WEIGHT 10
#define MAX_CUIT 11

typedef enum {HOMBRE, MUJER, REPETIDO, NUM_TIPOS}tipo_t;

const int tipo_values[NUM_TIPOS][2]={
    [HOMBRE] = {2,0},
    [MUJER] = {2,7},
    [REPETIDO] = {2,4},
};

const int weightValues[MAX_WEIGHT]={5,4,3,2,7,6,5,4,3,2};

long n_pot10(int pot){
    long valuePot = 1;
    for(size_t i=0; i<pot ; i++){
        valuePot *= 10;
    }
    return valuePot;
} 


uint64_t generar_cuit(tipo_t tipo, int dni){
    int dni_vec[MAX_DNI];
    size_t i;
    for(i=0 ; i<MAX_DNI ; i++){
        dni_vec[i]=dni/n_pot10(MAX_DNI- 1 - i);
        dni %= n_pot10(MAX_DNI - 1 - i);
    }

    int verDigit=0;
    for(i=0; i<10 ; i++){
        if(i<2){
            verDigit += tipo_values[tipo][i] * weightValues[i];
            continue;
        }
        
        verDigit += dni_vec[i-2] * weightValues[i];
    }

    if((verDigit % 11) == 0)
        verDigit = 0;
    else if((verDigit % 11) > 1)
        verDigit = 11 - (verDigit % 11);

    bool changeTipo = false;
    int changeTipoVec[2]={2,3};
    if((verDigit % 11) == 1){
        changeTipo = true;
        if(tipo == HOMBRE)
            verDigit = 9;
        if(tipo == MUJER)
            verDigit = 4;
        if(tipo == REPETIDO)
            verDigit = 3;
    };

    uint64_t cuit=0;
    for(i=0 ; i< MAX_CUIT ; i++){
        if(i < 2 && changeTipo){
            cuit += changeTipoVec[i] * n_pot10(MAX_CUIT - 1 - i);
            continue;
        }
        else if(i < 2){
            cuit += tipo_values[tipo][i] * n_pot10(MAX_CUIT - 1 -i);
            continue;
        }
        else if(i == MAX_CUIT-1){
            cuit += verDigit;
            continue;
        }
        
        cuit += dni_vec[i - 2] * n_pot10(MAX_CUIT - 1 -i);

    }

    return cuit;
}

int main(void){
    int dni  = 12345678;

    uint64_t cuit = generar_cuit(MUJER,dni);

    printf("cuit :\t%ld\n",cuit);

    return 0;
}