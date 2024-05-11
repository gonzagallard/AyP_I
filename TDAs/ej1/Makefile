#agregar programas a acompilar
PROGRAMS = barbara
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
LDFLAGS=-lm

.PHONY: clean confirm_clean

all: $(PROGRAMS).exe

$(PROGRAMS)	.exe:	barbara.o alan.o
	$(CC) barbara.o alan.o -o $(PROGRAMS).exe $(LDFLAGS)

barbara.o:	barbara.c alan.h
	$(CC) $(CFLAGS) -c barbara.c

alan.o: alan.c alan.h
	$(CC) $(CFLAGS) -c alan.c

val:
	@if [ -z "$(PROGRAM)" ]; then \
		echo "Error: Debes especificar el nombre del programa. Uso: make val PROGRAM=<nombre_del_programa>"; \
		exit 1; \
	fi
	valgrind ./$(PROGRAM).exe

cleanprog:
	@if [ -z "$(PROGRAM)" ]; then \
		echo "Error: Debes especificar el nombre del programa. Uso: make clean PROGRAM=<nombre_del_programa>"; \
		exit 1; \
	fi
	rm -f $(PROGRAM).exe

cleanall: confirm_clean
	rm -f *.exe *.out

confirm_clean:
	@echo "¿Deseas limpiar los archivos (*.exe, *.out *.o)? (Y/N)"
	@read answer; \
	if [ "$$answer" != "Y" ]; then \
		echo "Cancelando la limpieza."; \
		exit 1; \
	fi