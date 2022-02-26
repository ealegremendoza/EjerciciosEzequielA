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
	las funciones de manejo de sockets cuyos prototipos daban en el enunciado.
*/

#define	REJECT 		1
#define VALIDATE	0
#define TESTING_SOCKET_READ 	(REJECT)

#define	CONNECTION_ERROR		1
#define CONNECTION_SUCCES		0
#define TESTING_SOCKET_TIMEOUT 	(CONNECTION_SUCCES)


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

/**
* Separa el código del mensaje recibido por el Host.
* @param ResponseMessage, puntero al pensaje recibido por el Host.
* @return codigo del mensaje o -1 en caso de error.
*/
int GetCodeFromResponseMessage(char* ResponseMessage);

/**
* Arma el mensaje que será enviado al Host.
* @param typeMsg, puntero al tipo de mensaje a enviar. Ej "0200"
* @param cardNumLen, longitud del numero de la tarjeta.
* @param cardNum, puntero al numero de la tarjeta.
* @param amount, puntero al monto a pagar.
* @param code, puntero al codigo de seguridad de la tarjeta.
* @return puntero al mensaje o NULL en caso de error.
* @note retorna memoria dinámica. Debe liberarla luego de su uso.
*/
char* SetRequestMessage(char* typeMsg, int cardNumLen, char* cardNum, char* amount, char *code );

/**
* Borra un caracter determinado de una cadena de caracteres. 
* @param str, puntero a la cadena que va a ser modificada.
* @param char2del, caracter a borrar dentro de la cadena indicada.
* @return nada.
* note: la cadena cambiará de longitud.
*/
void DeleteCharOnString(char* str, char char2del);

/**
* Crea una cadena de caracteres a partir de otra, rellenando hacia izquierda con un
* caracter determinado una longitud determinada. 
* @param strOrig, puntero a la cadena a leer para rellenar la cadena resultante.
* @param ch2pad, caracter con el que se rellenará la cadena resultante.
* @param padlen, longitud final de la cadena.
* @return puntero al mensaje o NULL en caso de error.
* @note retorna memoria dinámica. Debe liberarla luego de su uso.
*/
char* StringPadding(char *strOrig, char ch2pad, int padlen);

/**
* Envía usando sockets la información de la tarjeta y el monto al Host, esperando
* su respuesta un tiempo determinado. El host responde con un mensaje que contiene
* un código indicando si la tarjeta es o no válida.
* @param ip, puntero a la cadena a leer de la ip del host.
* @param port, puntero a la cadena a leer del puerto del host.
* @param typeMsg, puntero a la cadena a leer el tipo de mensaje a enviar. Ej: "0200"
* @param cardNumLen, longitud del numero de la tarjeta.
* @param cardNum, puntero a la cadena a leer el numero de la tarjeta.
* @param amount, puntero a la cadena a leer el monto a debitarse de la tarjeta.
* @param code, puntero a la cadena a leer el codigo de seguridad de la tarjeta.
* @param maxResponseTimeout, tiempo en milisegundos de espera de la respuesta del Host.
* @return 0 por éxito o -1 en caso de error.
*/
int ValidateTransaction(const char *ip, unsigned short port,char* typeMsg, int cardNumLen,
				 char* cardNum, char* amount, char *code,int maxResponseTimeout);

