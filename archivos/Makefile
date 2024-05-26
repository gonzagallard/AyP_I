CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
LDFLAGS=-lm

.PHONY: clean confirm_clean

PROGRAMS = test	alan	#agregar programas a acompilar

all: $(PROGRAMS)

%:
	$(CC) $(CFLAGS) -o $@.exe $@.c

lm: 
	@if [ -z "$(PROGRAM)" ]; then \
		echo "Error: Debes especificar el nombre del programa. Uso: make lm PROGRAM=<nombre_del_programa>"; \
		exit 1; \
	fi
	$(CC) $(CFLAGS) -o $(PROGRAM).exe $(PROGRAM).c $(LDFLAGS)

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
