#!/bin/bash

echo "*******************************************************"
echo "Nombre del archivo:"
read -r file1
echo "*******************************************************" 
echo "Elija una opcion:"
echo "com = compile"
echo "coma = compile + math"
echo "comw = compile + Werror"
echo "val = ejecutarvlagirnd"
echo "esc = EXIT"
echo "********"
read -r opc
case ${opc} in
	com)	gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic -g; 
       	        echo "Compilation FILE C tried";;
        coma)   gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic -g -lm; 
       	        echo "Compilation MATH FILE C tried";;
        comw)	gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic -g -Werror; 
       	        echo "Compilation FILE C tried";;
        
        val)    valgrind --leak-check=full --track-origins=yes --show-reachable=yes -s ./"${file1}".exe;
                echo "Valgrind succes" ;;
        esc)  exit;
        
        exit;;
esac

