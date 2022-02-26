#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inputFunctions/inputFunctions.h"

#define _SOCKET_ERROR_		(-1)
#define _SOCKET_SUCCESS_	0

#define TYPE_MSG_LEN 		4
#define TARGET_LEN			12
#define RESPONSE_MENSSAGE_CODE_LEN	2
#define RESPONSE_MENSSAGE_LEN	6

#define MILISEC				1000
#define TIMEOUT_READ_MSG	5*MILISEC



#define VALID_CODE 0

/*  Las siguientes macros fueron realizadas a fin de poder simular el
	comportamiento del código, y que interpreté que sólo debía invocar
	las funciones de manejo de sockets cuyos prototipos daban en el enunciado.*/
#define	REJECT 		1
#define VALIDATE	0
#define TESTING_SOCKET_READ 	(REJECT)

#define	CONNECTION_ERROR		1
#define CONNECTION_SUCCES		0
#define TESTING_SOCKET_TIMEOUT 	(CONNECTION_SUCCES)



//esto lo traje de inputFunctios.h


// 	Interpreté que sólo debía invocar las funciones de socket del enunciado.

/**
* Crea un socket
* @return handle del socket o -1 en caso de error
*/
int socketCreate();

/**
* Conectar el socket a un host
* @param handle handle del socket a utilizar
* @param ip direccion ip del host a conectarse
* @param port puerto del host a conectarse
* @return handle del socket o -1 en caso de error
*/
int socketConnect(int handle, const char *ip, unsigned short port);


/**
* Leer datos del socket. La función bloquea hasta leer datos o transcurrir maxTimeout milisegundos
* @param handle handle del socket a utilizar
* @param data puntero donde se guardarán los datos leidos
* @param maxTimeout tiempo máximo de espera en milisegundos
* @return  cantidad de bytes leidos o -1 en caso de error
*/
int socketRead(int handle, unsigned char *data, int maxTimeout);


/**
* Escribir datos en un socket.
* @param handle handle del socket a utilizar
* @param data puntero donde se leerán los datos a escribir
* @return cantidad de bytes escritos o -1 en caso de error
*/
int socketWrite(int handle, const unsigned char *data);


int GetCodeFromResponseMessage(char* ResponseMessage);


char* SetRequestMessage(char* typeMsg, int cardNumLen, char* cardNum, char* amount, char *code );
void DeleteCharOnString(char* str, char char2del);
char* StringPadding(char *strOrig, char ch2pad, int padlen);

int ValidateCard(const char *ip, unsigned short port,char* typeMsg, int cardNumLen,
				 char* cardNum, char* amount, char *code,int maxResponseTimeout);

