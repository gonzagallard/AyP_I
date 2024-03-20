#!/bin/bash

echo "*******************************************************"
echo "Nombre del archivo:"
read -r file1
echo "*******************************************************" 
echo "Elija una opcion:"
echo "comc = compile"
echo "esc = EXIT"
echo "********"
read -r opc
case ${opc} in
	comc)	gcc -o "${file1}".exe "${file1}".c -Wall -std=c99 -pedantic; 
       	        echo "Compilation FILE C tried";;
        esc)  exit;
        
        exit;;
esac

