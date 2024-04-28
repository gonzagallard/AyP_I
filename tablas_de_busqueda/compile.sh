#!/bin/bash

echo "*******************************************************"
echo "Nombre del archivo:"
read -r file1
echo "*******************************************************" 
echo "Elija una opcion:"
echo "com = compile"
echo "coma = compile + math"
echo "esc = EXIT"
echo "********"
read -r opc
case ${opc} in
	com)	gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic -g; 
       	        echo "Compilation FILE C tried";;
        coma)   gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic -g -lm; 
       	        echo "Compilation MATH FILE C tried";;
        esc)  exit;
        
        exit;;
esac

