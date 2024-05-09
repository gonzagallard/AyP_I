/*
Un sintetizador de una radio digital posee un generador de frecuencia controlado por el siguiente registro:
     bit 7 |   6   |   5   |   4   |   3   |   2   |   1   | bit 0 |
    +-------+-------+-------+-------+-------+-------+-------+-------+
    |  AFT  | BNDAM |   E   |   D   |   C   |   B   |   A   |  SYN  |
    +-------+-------+-------+-------+-------+-------+-------+-------+
    AFT                 Control de Sintonía Fina Automática (1 = ON , 0 = OFF).
    BAND                Control de selección de banda AM (1 = AM , 0 = FM).
    E, D, C, B, A       Factor de división de la frecuencia de reloj (ver tabla).
    SYN                 Control de activación del sintetizador (1 = ON, 0 = OFF).

    E   D   C   B   A       Factor de división (FDIV)
    0   0   0   0   0           1
    0   0   0   0   1           2   
    0   0   0   1   0           3
    .. ..  ..   ..  ..          ..
    1   1   1   1   1           32

Se pide:

Escriba el código de una función denominada get_synthesizer_divider() que devuelva por su nombre el factor de división a partir de los bits A, B, C, D y E contenidos en el byte de control. El prototipo de la función pedida es:

int get_synthesizer_divider(uint8_t);
Dar un ejemplo de invocación de la función.

Escriba el código de una función denominada es_am() que reciba como parámetro el registro de control, y retorne por si está seleccionada la banda de AM. Dar un ejemplo de invocación.

NOTA: Debe utilizarse máscaras y operadores de bits para operar con los bits del registro de datos.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASK_8U_FACTOR 0x3EU
#define SHIFT_FACTOR 1

#define MASK_8U_AM 0x40U

int get_synthesizer_divider(const uint8_t reg);

bool es_am(const uint8_t reg);

int main(void){
    uint8_t registro = 0x87U;
    int factorDiv = get_synthesizer_divider(registro);

    printf("Valor de factor de conversion:\t%d\n",factorDiv);

    if(es_am(registro))
        puts("AM esta prendido");
    else
        puts("AM no esta prendido");

    return 0;
}

int get_synthesizer_divider(const uint8_t reg){
    uint8_t aux = reg & MASK_8U_FACTOR;

    return (aux >> SHIFT_FACTOR) + 1;
}
bool es_am(const uint8_t reg){
    return reg & MASK_8U_AM;
}

