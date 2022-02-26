#include <stdio.h>
#include <string.h>

typedef struct {
  char rangeLow[8+1];
  char rangeHigh[8+1];
  unsigned char len;
  int id;
} range_t;

typedef struct{
  char label[12+1];
  int id;
}card_t;


#define MAX_CARD_DIGITS 20
#define MIN_CARD_DIGITS 13
#define RANGE_DIGITS	8
#define MIN_ID 			0
#define NUM_REGS		3
#define	NUM_RANGE_REGS	NUM_REGS
#define	NUM_CARD_REGS	NUM_REGS
#define PATH_RANGES		"./ranges.dat"
#define PATH_CARDS		"./cards.dat"
#define INVALID_ID  (-1)

int genCardsFile(const char *path);
int genRangesFile(const char *path);

int readCardsFile(const char *path);
int readRangesFile(const char *path, const char *ascNumCard);
int IsCardCodeinRange(const char* ascCardCode, range_t range);
int IsCardNumLenghtMatches(const char* ascCardNum, range_t range);