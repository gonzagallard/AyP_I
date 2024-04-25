#include <stdio.h>

int main(void){
    float var, set[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    //float *p;

    //p = set; //  correcta, set es el primer elemento set[0]
   // var = *p; 
    //*p=10.0;

////////////
    int conj[5], list[]={5, 4, 3, 2, 1};
    int *punt;

    punt = list;
    //conj = punt; //incorrecto conj es un arreglo de 5 tipos int y punt es un puntero a int
    //list = conj; //incorrecto list es la direccion de list[0] y conj[0] tambien, list no es un puntero a tipo int
    //punt = &conj;//correcto conj es la direccion del puntero que apunta a &conj[0] = &conj

/////////////

    int *pint, arrayint[5];
    float *pfloat, arrayfloat[5];

    pint = arrayint;
    pfloat = arrayfloat;
    pint += 1;  //direccion del segundo elemento arrayint[1]
    pfloat += 1;    //direcion del segundo elemento arayfloat[1]
    pint++;        //idem arraint[2]
    pfloat++;   //idem  arrayfloat[2]
    pint -= 1;  //direccion del elemento anterior arrayint[1]
    pfloat -=1; //direccion del elemento anterior

//////////////
    int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 

    int var;
    p = a;
    *p = 33;   //elemento 0 del arreglo se cambia a 33
    var = *p;   //se asigna 33 a la variable var
    var = *(p+1);   //se asigna el elemento 2 del arreglo a var
    var = *(p+3);
    var = *(p++);   //se asigna el elemento actual a var y se pasa al siguiente elemento
    var = *p++; // se desreferencia p, se asigna y luego se incrementa
    var = *(++p); //se pasa al siguiente elemento de a y luego se asigna a var
    var = *++p;// idem anterior
    var = ++*p;//se desreferencia p, se incrementa +1 y luego se asigna
    var = (*p)++;//demm *p++
    var = ++(*p);//idem ++*p
    var = *p+1; //se dereferencia p se aumenta +1 y luego se asigna

    /////////////
    //int *p, a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    var = *(a+1);//solo se explor el elemento siguiente no se incrementa
    var = *(a++);// a es un arreglo que no puede ser incrementado, no es un puntero comun 





    return 0;
}