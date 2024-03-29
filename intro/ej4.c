/*Escribir una función que dadas la hora, minutos y segundos devuelva el tiempo en segundos*/

#include <stdio.h>
#include <stdbool.h>

#define EXIT_SUCCESS 0
#define EXIT_FAIL -1
#define MIN_TIME 0

int in_data(void);
bool data_invalid(int data);
int time_to_seconds(int hour, int min, int seg);

int main(void){
    int hour, min, seg ;
    hour = min = seg = 0;

    printf("Ingrese las horas: \t");
    if(data_invalid(hour = in_data()))
        return EXIT_FAIL;

    printf("Ingrese las minutos: \t");
    if(data_invalid(min = in_data()))
        return EXIT_FAIL;

    printf("Ingrese las segundos: \t");
    if(data_invalid(seg = in_data()))
        return EXIT_FAIL;
    
    seg = hour * 3600 + min * 60 + seg;
    printf("%d horas, %d minutos, %d segundos ==>  %d segundos totales\nFIN PROGRAMA\n"
            ,hour, min, seg, time_to_seconds(hour, min, seg));

    return EXIT_SUCCESS;
}

int in_data(void){
    int data;
    scanf("%d", &data);
    return data;
}

bool data_invalid(int data){
    if(data < MIN_TIME){
        printf("Datos invalidos\nCERRANDO PROGRAMA\n");
        return true;
    }
    return false;
}

int time_to_seconds(int hour, int min, int seg){
    return hour * 3600 + min * 60 + seg;
}
