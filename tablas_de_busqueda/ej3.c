/*
El autopiloto de un vehículo aéreo autónomo (UAV) soporta la comunicación con una computadora 
externa a través de un puerto serie que admite las siguientes velocidades :
 9600, 19200, 34800, 57600, 115200, 230400, 460800, 500000 y 921600, en Baudios (baudrate).

Definir un tipo enumerativo que contenga dichos valores.

Escribir una porción de código en la que, en función de un entero que almacena un valor de baudrate, 
se almacene un valor adecuado en una variable del tipo enumerativo definido anteriormente.

*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_ARR 50

typedef enum {v9,v19,v34,v57,v115,v230,v460,v500,v921,v_num}velTransf_t;

const int vel_data[v_num] = {
    [v9] = 9600,
    [v19] = 19200,
    [v34] = 34800,
    [v57] = 57600,
    [v115] = 115200,
    [v230] = 230400,
    [v460] = 460800,
    [v500] = 500000,
    [v921] = 921600,
};

velTransf_t give_vel(const int data){
    size_t i;
    for(i=0;i<v_num;i++){
        if(data == vel_data[i])
            break;
    }
    return i != v_num ? i : v_num;
}

void set_vel(int *setVar, velTransf_t vel){
    *setVar = vel_data[vel];
}

int main(void){
    char data_in[MAX_ARR];
    if((fgets(data_in,MAX_ARR,stdin))==NULL){
        puts("NO SUCCESS 1");
        return 1;
    }
    int data_int = atoi(data_in);
    velTransf_t velrate = give_vel(data_int);
    if(velrate == v_num){
        puts("NO SUCCESS 2");
        return 1;
    }
    
    int vel = 0;
    set_vel(&vel, velrate);
    printf(">>>>%d\n",vel);
    puts("SUCCESS");
    return 0;
}

