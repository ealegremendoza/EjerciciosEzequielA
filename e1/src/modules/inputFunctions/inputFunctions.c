//inputFunctions.c
#include "inputFunctions.h"

/*	brief: Verifica si todos los caracteres de la cadena corresponden a números. 
	@param str, en este puntero la cadena de caracteres.
	@return  __TRUE__ (1) por exito, __FALSE__(0) por error.
*/
char allNumbers(char *str){
	int count=0;
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]>='0' && str[i]<='9')
			count++;
	}	
	return  (count==strlen(str)) ? _SUCCESS_:_ERROR_;
}



/*
	brief: La función solicita al usuario una indeterminada cantidad de números enteros.
	@param stopChar, este es el caracter que dará finalización a la carga de números.
	@param inputMsg, mensaje personalizado para solicitar que ingresen datos.
	@return  Retorna 1 en caso de exito. Retorna 0 en caso de error. 
*/
int inputNumbers(const char* inputMsg, char stopChar)
{
	FILE *tempFile;
	char ascNum[100];
	char strnum[100];
	int inputNumber=0;
	int padLen=0;
	const char *padding="0000000000";

	//Creo un archivo temporal para almacenar los numeros
	tempFile=fopen("tmp.txt","w");
	if(NULL==tempFile){
		printf("> Error al crear el archivo tmp.txt.\n");
		return _ERROR_;
	}
	fclose(tempFile);

	while(1){
		printf("%s\n",inputMsg);
		scanf("%s",ascNum);

		if(TARGET_LEN<strlen(ascNum)){
			printf("> Error. Ingrese hasta %d dígitos por favor.\n",TARGET_LEN);
			continue;
		}

		if(_SUCCESS_==allNumbers(ascNum) ){
			inputNumber=atoi(ascNum);
			if((stopChar-'0')==inputNumber){
				
				return _SUCCESS_; //salgo del while(1)
			}
			else{
				tempFile=fopen("tmp.txt","a+");
				if(NULL==tempFile){
					printf("> Error al abrir el archivo.\n");
					return _ERROR_;
				}
				sprintf(strnum,"%d",inputNumber);
				padLen = TARGET_LEN - strlen(strnum);
				if(padLen < 0) padLen = 0;
				fprintf(tempFile,"%*.*s%s\r\n", padLen, padLen, padding, strnum);
				fclose(tempFile);
			}
		}
		else{
			printf("> Error. Ingrese sólo números por favor.\n");
			continue;
		}

	}

	return _SUCCESS_;
}




/*	brief: La función verifica si el nombre asignado al archivo es válido
	@param ptr, puntero a memoria dinámica para liberar.
	@return  nada.
*/
int checkFileName(char* path){
	int indexPath;
	int lenPath=strlen(path);

	if(lenPath>PATH_CHARACTER_LIMIT) 
		return _ERROR_;

	for(indexPath=0;indexPath<lenPath;indexPath++){
		if( (path[indexPath]>='A' && path[indexPath]<='Z')||
			(path[indexPath]>='a' && path[indexPath]<='z')||
			(path[indexPath]>='0' && path[indexPath]<='9')||
			(path[indexPath]=='-'|| path[indexPath]=='_')){

			continue;
		}else{
			printf("> Error. El nombre de archivo inválido.\n");
			return _ERROR_;
		}
	}
	return _SUCCESS_;
}





/*	brief: La función solicita que se ingrese el nombre de un archivo.
	@param inputPath, nombre del archivo que se creará.
	@return  1 en caso de éxito. 0 en caso de error. 
*/
char* InputNameFile(void){
	char *inputPath;
	inputPath=(char*)malloc(sizeof(char)*(PATH_CHARACTER_LIMIT+1));
	do{
		printf("> Ingrese el nombre del archivo que desea crear por favor.\n");
		printf("> El mismo solo pude contener caracteres alfanuméricos: a-z y 0-9, y/o guiones.\n");
		scanf("%s",inputPath);
	}while(_ERROR_== checkFileName(inputPath));
	strcat(inputPath,".txt");
	return inputPath;
}



