#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define _ERROR_		0
#define _SUCCESS_ 	1

#define MAX_LEN_STR	100

#define AMOUNT_SIZE	(12) 

#define SECURITY_CODE_LEN	3

#define MIN_LEN_CARD_NUMBER	13
#define MAX_LEN_CARD_NUMBER	20






/**
 * brief: Verifica si todos los caracteres de la cadena corresponden a números decimales positivos 
 * @param str, en este puntero la cadena de caracteres.
 * @return  1 en caso de exito, 0 en caso de error.
*/
int IsAPositiveDecimalNumber(char *inputString);


/**
 * brief: Verifica si todos los caracteres de la cadena corresponden a números. 
 * @param str, en este puntero la cadena de caracteres.
 * @return  1 en caso de exito, 0 en caso de error.
*/
char IsStringOnlyNumbers(char *str);

/**
* Solicita al usuario ingresar el monto de la compra. Sólo permite el ingreso
* de números decimales positivos (Ej: 12 o 12.5)
* @return puntero a una cadena con el valor del monto filtrado.
* @note retorna memoria dinámica. Debe liberarla luego de su uso.
*/
char* RequestPurchaseAmount(void);


/**
* Solicita al usuario ingresar el numero de la tarjeta.
* @return puntero a una cadena con el numero de la tarjeta filtrado.
* @note retorna memoria dinámica. Debe liberarla luego de su uso.
*/
char* RequestCardNumber(void);

/**
* Solicita al usuario ingresar el codigo de seguridad de la tarjeta.
* @return puntero a una cadena con el codigo de seguridad de la tarjeta filtrado.
* @note retorna memoria dinámica. Debe liberarla luego de su uso.
*/
char* RequestCardSecurutyCode(void);

