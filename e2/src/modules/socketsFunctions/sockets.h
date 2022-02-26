#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "../inputFunctions/inputFunctions.h"
//#include "../cardFunctions/card.h"

#define TYPE_MSG_LEN 		4
#define _SOCKET_ERROR_		(-1)
#define _SOCKET_SUCCESS_	0
#define TARGET_LEN			12
#define SOCKET_IP_LOCAL_HOST		"127.0.0.1"
#define SOCKET_PORT				3490  // MAYOR A 1023
#define MILISEC					1000
#define TIMEOUT_READ_MSG		5*MILISEC

#define	REJECT 		1
#define VALIDATE	0
#define TESTING 	(REJECT)

char* SetRequestMessage(char* typeMsg, int cardNumLen, char* cardNum, char* amount, char *code );
void DeleteCharOnString(char* str, char char2del);
char* StringPadding(char *strOrig, char ch2pad, int padlen);

int ValidateCard(const char *ip, unsigned short port,char* typeMsg, int cardNumLen,
				 char* cardNum, char* amount, char *code,int maxResponseTimeout);

//no llegue a implementar las funciones de socket.
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

