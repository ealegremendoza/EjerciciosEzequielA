//ejercicio1.c
/*
Escriba un programa que solicite al usuario el ingreso de números enteros y los guarde en un
archivo de acuerdo a los siguientes requerimientos:
-Se solicitará el ingreso de números hasta que se ingrese un valor igual a 0 que no debe ser
guardado.
-Al finalizar el ingreso se solicitará ingresar el nombre del archivo en el que se desean guardar los
números.
-El formato a utilizar en el archivo será de cadenas de 10 caracteres. Para los números que tengan
menos de 10 caracteres se rellenará con el carácter ‘0’ hasta completar la cadena. Los cadenas deben
quedar separadas en el archivo mediante un salto de línea CRLF.
-Se informará si el archivo fue guardado con éxito o si falló y luego terminará la ejecución del
programa.

*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num_index=0;
	int i=0;
	int *vector_numeros=NULL;
	char nombre_archivo[100];
	FILE *archivo;
	int padLen;
	const char *padding="0000000000000000000";
	char str_num[100];

	vector_numeros=(int*)malloc(sizeof(int));
	if(NULL==vector_numeros){
		printf("Error.No pudo solicitarse memoria.\n");
		return -1;
	}

	

	while(1){
		printf("Ingrese un nuevo número:\n");
		scanf("%d",&vector_numeros[num_index]);

		if(0==vector_numeros[num_index]){
			printf("Ingrese el nombre del archivo:\n");
			scanf("%s",nombre_archivo);
			break;
		}	
		sprintf(str_num,"%d",vector_numeros[i]);
		
		vector_numeros=(int*)realloc(vector_numeros,sizeof(int)*(num_index+1));
		num_index++;
	}
	printf("El archivo %s fue creado con éxito.\n",nombre_archivo);
	printf("indice:%d,tamanio de vector: %d\n",num_index,(int)sizeof(vector_numeros));

	while(num_index)
	{
		printf("vector_numeros[%d]=%d\n",i,vector_numeros[i]);
		num_index--;
		i++;
	}

	strcat(nombre_archivo,".txt");
	archivo=fopen(nombre_archivo, "a+");
  	if(archivo == NULL) 
	{ 
		printf("No se pudo abrir el archivo... \n"); 
		return -1; 
  	}

  	fprintf(archivo,"[%*.*s%s]\r\n",padLen,padLen,padding,string);

	fclose(archivo);
	free(vector_numeros);
	return 0;
}