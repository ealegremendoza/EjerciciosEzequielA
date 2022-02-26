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
#define NUM_REGS    3
#define NUM_RANGE_REGS  NUM_REGS
#define NUM_CARD_REGS NUM_REGS
#define PATH_RANGES   "./ranges.dat"
#define PATH_CARDS    "./cards.dat"
#define INVALID_ID  (-1)
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



char* RequestCardNumber(void);

int genCardsFile(const char *path);
int genRangesFile(const char *path);
int genCardsRegs(void);

int readCardsFile(const char *path, const int cardId);
int readRangesFile(const char *path, const char *ascNumCard);
int verifyCardNumber (const char* ascCardNum);

int IsCardCodeinRange(const char* ascCardCode, range_t range);
int IsCardNumLenghtMatches(const char* ascCardNum, range_t range);
int CardIdMatches(int cardId,card_t card);
