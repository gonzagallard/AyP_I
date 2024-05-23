/*
argc y argv son argumentos que recibe la funcion main con un nombre estandar

argv es el vector de comandos de la linea de argumentos que provienen de linea de comandos, 
    que configuran al main con valores determinados

    Todos los command-line arguments son transferidos como strings
    argv[0] es el nombre del programa invocado

argc es un entero que sirve para procesar el vector argv
    como valor tiene la cantidad de N argumentos
    argv[argc] es NULL por convencion;

Ej2
    $ ./programa -s "Hola Mundo!"
    argc = 3
    argv[argc] ==> {"./programa", "-s", "Hola Mundo!", NULL}  // 

    argv[0] = "./programa"
    argv[1] = "-s"
    argv[argc - 1] = "Hola Mundo!"
    argv[argc] = NULL
*/