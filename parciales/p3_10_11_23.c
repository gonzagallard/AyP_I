/*
1. Se quiere modelar el TDA votación, que permita decidir entre diferentes opciones.
Se pide:
    a. Declarar la estructura que encapsula el TDA. Explicar qué representa
        cada miembro y documentar la invariante de representación.
    b. Implementar la primitiva float votacion_porcentaje_opcion(const
        votacion_t *v, const char *opcion); que devuelva el porcentaje de
        votos de la opcion.
    c. Implementar la primitiva bool votacion_votar(votacion_t *v,
        const char *opcion); que agregue la opción a la lista de opciones.
        votacion_t *v = votacion_crear();
        votacion_votar(v, "membrillo");
        votacion_votar(v, "batata");
        votacion_votar(v, "pastelera");
        votacion_votar(v, "batata");
        votacion_porcentaje_opcion(v, "membrillo"); // 0.25 o 25
*/  
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>

    typedef enum {OPC_MEMBRILLO,OPC_BATATA,OPC_PASTELERA,OPC_NINGUNA}opcion_t;

    char const*const name_opciones[]={
        [OPC_MEMBRILLO] = "membrillo",
        [OPC_BATATA]    = "batata",
        [OPC_PASTELERA] = "pastelera",
        [OPC_NINGUNA]   = "",
    };


    struct votacion{
        size_t votos_miembros[3];   //vector que guarda los votos de cada miembro de las opciones
        size_t nvotos;              //nvotos  == suma de todos los valores en votos_miembros
    };
    
    typedef struct votacion votacion_t;

    float votacion_porcentaje_opcion(const votacion_t *v, const char *opcion){
        size_t total_votos = v->nvotos;
        size_t i;
        for(i=0 ; i < OPC_NINGUNA ; i++){
            if(!strcmp(opcion, name_opciones[i]))
                break;
        }
        return (float)v->votos_miembros[i]/total_votos;
    }

    bool votacion_votar(votacion_t *v, const char *opcion){
        size_t i;
        for(i=0; i < OPC_NINGUNA; i++){
            if(!strcmp(opcion, name_opciones[i])){
                v->votos_miembros[i]++;
                v->nvotos++;
                return true;
            }
        }
        return false;
    }

    int main(void){
        votacion_t *votacionCreada = malloc(sizeof(votacion_t));
        if(votacionCreada==NULL) return EXIT_FAILURE;
        
        votacionCreada->nvotos = 0;

        votacion_votar(votacionCreada, "membrillo");
        votacion_votar(votacionCreada, "batata");
        votacion_votar(votacionCreada, "pastelera");
        votacion_votar(votacionCreada, "batata");
        
        printf("porcentaje:\t%.2f\n",votacion_porcentaje_opcion(votacionCreada,"membrillo"));

        return EXIT_SUCCESS;
    }




