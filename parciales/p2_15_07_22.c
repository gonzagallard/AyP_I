/*
1. La tabla ASCII está diseñada para realizar determinadas operaciones de forma sencilla mediante manejo de bits.
    Algunas de ellas son:
        Todas las mayúsculas son de la forma 010xxxxx donde xxxxx representa el número de letra (entre 1 y 26).
        Todas las minúsculas son de la forma 011xxxxx donde xxxxx representa el número de letra (entre 1 y 26).
Utilizando operaciones de bits implementar las siguientes funciones:

bool es_minuscula(char c); // Indica si un caracter es minúscula
char a_mayusculas(char c); // Si una letra es minúscula la convierte a mayúsculas

Nota: El ejercicio debe resolverse utilizando bits. Se permite utilizar comparaciones sobre los valores indicados con
equis en los ejemplos. No se permite resolver los ejercicios con operaciones de comparación sobre el ASCII completo (es
decir, es_minúscula puede incluir chequear xxxxx <= 26 pero no puede incluir c <= 'z' o c <= 'a'.)


2. Implementar una función
        char *join(const char **ss, char sep);
    que reciba en ss un arreglo dinámico de cadenas y devuelva la concatenación de cada una de ellas separadas por el
    separador sep. La cantidad de cadenas está indicada con un centinela NULL en la última posición.
    Por ejemplo join({"Hola", "que", "tal", NULL}, '|') debe devolver "Hola|que|tal".

3. Implementar una función
        int *generar_ruido(int maximo, size_t *n);
    que llame a la función int rand(void); sucesivas veces hasta que la misma devuelva un valor superior a maximo. Todos
    los valores devueltos por random() deben ser almacenados en un vector y devueltos. En n devolver la cantidad de
    valores almacenados.
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MASK_8U_MAY_MIN     0x20U


bool es_minuscula(char c){
    return (c & MASK_8U_MAY_MIN);
}
char a_mayusculas(char c){
    if(es_minuscula(c)){
        c &= (~MASK_8U_MAY_MIN);    
        return c;
    }
    return c;
}
/*
bool es_minuscula (char c) {
  return  ((c>>5 == MASK_MINUSCULA) && ((c & MASK_LETRAS)<=26));
}

char a_mayuscula (char c) {
 return (es_minuscula(c)?(c&MASK_A_MAYUSCULA):c);
}
*/

char *joinGonza(const char **ss, char sep){
    size_t ncadenas;
    for(ncadenas=0 ; ss[ncadenas] ; ncadenas++);

    char separador[2]= {sep, '\0'};

    int largo = strlen(ss[0]);

    char *cadena = malloc((largo+1) * sizeof(char)); //+1 para el caracter cero
    if(cadena == NULL)
        return NULL;
    
    strcpy(cadena, ss[0]);
    size_t i;
    for(i = 1 ; i < ncadenas ; i++){
        largo += strlen(ss[i]) + 1;
        char *aux = realloc(cadena,(largo + 1) * sizeof(char));
        if(aux == NULL){
            free(cadena);
            return NULL;
        }
        cadena = aux;
        strcat(cadena, separador);
        strcat(cadena, ss[i]);
    }
    return cadena;
}
/*
char *join (const char **ss, char sep) {
  size_t size=0;
  size_t i=0;
  // for (size_t i=0;ss[i]);i++
  for (;ss[i];i++)
      size+=strlen(ss[i])+1;
  
  char *p=malloc(size*sizeof(char));
  if (!p)
     return NULL;

  size_t ip=0;
  for(size_t i=0;ss[i];i++){
     for  (size_t j=0;ss[i][j];j++,ip++)
          p[ip]=ss[i][j];
     p[ip]=sep;
 //   *(p+ip)=sep;  OTRA FORMA DE asignar 
     ip++;
   }
   p[--ip]='\0';
   return p;
 }

*/

int *generar_ruido(int maximo, size_t *n){
    int *vector = malloc(1 * sizeof(int));
    if(vector == NULL){
        *n = 0;
        return NULL;
    }
    bool esMaximo = false;
    int valor;
    size_t nvalores = 0;
    while(!esMaximo){
        valor = rand();
        vector[nvalores++] = valor;
        if(valor > maximo){
            esMaximo = true;
            continue;
        }
        int *aux = realloc(vector, (nvalores + 1) * sizeof(int));
        if(aux == NULL){
            free(vector);
            return NULL;
        }
        vector = aux;
    }
    *n = nvalores;
    return vector;
}
/*
int *generar_ruido (int maximo, size_t *n){
 size_t res;
 int *p=NULL;
 srand(time(NULL));

 int *aux;
 res=rand()%100;
 *n=0;
 while (res<maximo) {
         printf("%d %d\n",res,*n);

    aux=realloc(p,sizeof(int)* (1+*n));
   if (!aux){
       free(p);
       return NULL;
      }
    p=aux;
    *(p+*n)=res;
//    p[*n]=res;        otra orma de asignar
    *n+=1;
    res=rand()%100;
  }
  return p;
}
*/

int main(void){
    char registro = 'z';

    putchar(registro);
    putchar('\n');

    if(es_minuscula(registro))
        puts("Es minuscula");
    else
        puts("No es minuscula");
    
    char toMAyus = a_mayusculas(registro);
    
    putchar(toMAyus);
    putchar('\n');

    const char *arreglo[]= {"Hola", "que", "tal", NULL};
    char *cadena = joinGonza(arreglo,'|');

    puts(cadena);
    free(cadena);

    size_t n = 0;
    int *vector = generar_ruido(3000, &n);
    for(size_t i = 0; i < n; i++)
        printf("Maximo\t%d\tnvalores\t%ld\n",vector[i],n);

    return 0;
}