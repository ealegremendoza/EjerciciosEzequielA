//main.c
#include "app.h"
int main (void){
	char *inputNewNameFile;

	printf("> A continuación podrá ingresar solamente números enteros positivos hasta un máximo de %d dígitos.\n",STORAGE_LEN);
	printf("> Ingrese 0 para finalizar la carga de números.\n");

	if(inputNumbers("> Ingrese un número entero:",STOP_CHAR)){
		printf("> Numeros cargados con éxito.\n");

		// Procedeo a solicitar al usuario a ingresar el nombre para el archivo.
		// la funcion inputNewNameFile verifica si los caracteres del nombre son correctos.

		inputNewNameFile=InputNameFile();
		if(!rename("tmp.txt",inputNewNameFile)){
			printf("> El archivo %s ha sido creado con éxito.\n",inputNewNameFile);
		}
		else{
			printf("> Error al crear el archivo %s.\n",inputNewNameFile);	
		}

	}
	else{
		printf("> Error. Problema al cargar los números.\n");	
	}

	free(inputNewNameFile);
	return 0;
}

