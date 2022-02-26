#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _ERROR_   0
#define _SUCCESS_   1
#define MAX_CARD_DIGITS 20
#define MIN_CARD_DIGITS 13
#define RANGE_DIGITS  8
#define LABEL_LENG    12

#define MIN_ID      0
#define INVALID_ID  (-1)
#define NUM_REGS    3
#define NUM_RANGE_REGS  NUM_REGS
#define NUM_CARD_REGS   NUM_REGS
#define PATH_RANGES   "./ranges.dat"
#define PATH_CARDS    "./cards.dat"
#define INVALID_MSG   "TARJETA NO SOPORTADA"

typedef struct {
  char rangeLow[RANGE_DIGITS+1];
  char rangeHigh[RANGE_DIGITS+1];
  unsigned char len;
  int id;
} range_t;

typedef struct{
  char label[LABEL_LENG+1];
  int id;
}card_t;



/**
* Genera el archivo binario correspondiente a la información de las
* tarjetas. 
* @param path puntero a la ruta y nombre del archivo que quiere crearse.
* @return 0 por error, 1 por exito.
*/
int genCardsFile(const char *path);

/**
* Genera el archivo binario correspondiente a los rangos en
* que pueden encontrarse los primeros 8 dígitos de la tarjeta. 
* @param path puntero a la ruta y nombre del archivo que quiere crearse.
* @return 0 por error, 1 por exito.
*/
int genRangesFile(const char *path);

/**
* Realiza el armado de los registros de rangos y tarjetas.
* @return 0 por error, 1 por exito.
*/
int genCardsRegs(void);

/**
* Busca en el archivo de registros de tarjetas la tarjeta correcta
* mediante su ID. Imprime el label de la tarjeta.
* @param path puntero a la ruta y nombre del archivo que quiere leerse.
* @param cardId numero de identificacion de la tarjeta.
* @return 0 por error, 1 por exito.
*/
int readCardsFile(const char *path, const int cardId);

/**
* Busca en el archivo de registros de rangos el ID de la tarjeta.
* @param path puntero a la ruta y nombre del archivo que quiere leerse.
* @param ascCardNum puntero al numero de la tarjeta leida.
* @return 0 por error, 1 por exito.
*/
int readRangesFile(const char *path, const char *ascNumCard);

/**
* Verifica si el numero de la tarjeta leida se encuentra en los 
* registros del sistema.
* @param ascCardNum puntero al numero de la tarjeta leida.
* @return 0 por error, 1 por exito.
*/
int verifyCardNumber (const char* ascCardNum);

/**
* Verifica si el numero de la tarjeta leida se encuentra en dentro
* del rango de alguno de los registros.
* @param ascCardCode, puntero a los primeros 8 números de la tarjeta leida.
* @param range, puntero a la estructura que contiene la información en RangeLow
* y RangeHigh a utilizar en la función
* @return 0 por error, 1 por exito.
*/
int IsCardCodeinRange(const char* ascCardCode, range_t* range);

/**
* Verifica si el largo del numero de la tarjeta leida coincide con la longitud
* guardada en alguno de los registros.
* @param ascCardNum, puntero al número de la tarjeta leida.
* @param range, puntero a la estructura que contiene la información en range.len
* @return 0 por error, 1 por exito.
*/
int IsCardNumLenghtMatches(const char* ascCardNum, range_t* range);


/**
* Verifica si el ID de la tarjeta coincide con alguno de los ID guardados
* en los registros.
* @param cardId, número de identificación de la tarjeta leida.
* @param card, puntero a la estructura que contiene la información en id
* @return 0 por error, 1 por exito.
*/
int CardIdMatches(int cardId,card_t* card);
