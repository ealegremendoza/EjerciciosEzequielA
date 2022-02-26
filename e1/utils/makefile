#-----------------------------------------------------------------------
# Solo modificar las siguientes variables
# El nombre del programa:
BINARY = e1
# Nombre de los archivos pero modificando a .o:
OBJS = 	../src/main.c 
		
		#../src/modules/inputFunctions/inputFunctions.c

# Los headers:
HEADERS = ../src/app.h
# funciones
FUNCIONES= ../src/modules/inputFunctions/inputFunctions.c
# Flags:
CFLAGS = -Wall -g

# SI HAY QUE LINKEAR POR EJ CON -lm ponerlo aqui abajo, sino dejar vacio 
LDFLAGS = 

# Compilador:
CC = gcc
#-----------------------------------------------------------------------
# La siguien regla se ejecuta por default si coloco solo "make" 
# en la consola porque está primero.
all:
	@echo ' '
	@echo 'Uso'
	@echo 'make compile:	Compila y linkea.'
	@echo 'make execute:	Ejecuta la aplicación.'
	@echo 'make clean:	Borra el archivo binario.'
	@echo ' '
 
# Esta regla compila el programa principal.
# De ser necesario, agregar aqui LDFLAGS
compile: $(OBJS)
	@echo ' '
	@echo 'Compilando todos los objetos...'
	$(CC) $(FUNCIONES) -o $(BINARY) $(OBJS) $(LDFLAGS)  
	@echo 'Fin de la compilacion.'
	@echo ' '
	@echo 'Eliminando todos los archivos objeto...'
	rm -f *.o
	@echo 'Listo.'
	@echo ' '
# La siguiente regla convierte todo archivo.c de esta carpeta
# en un archivo.o
# el sibolo %.c indica q todos los .c son sus dependencias.
# el simbolo $? selecciona todos lso archivos .c
%.o: %.c $(HEADERS)
	@echo 'Creando objeto $@ ...'
	gcc $(CFLAGS) -c $?
	@echo 'Listo.'

execute:
	./$(BINARY)

# Esta regla borra el binario creado.
clean:
	@echo 'Borrando archivo binario...'
	rm $(BINARY)
	@echo 'Listo.'
	@echo ' '
