#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "../inputFunctions/inputFunctions.h"
//#include "../cardFunctions/card.h"

#define TYPE_MSG_LEN 4
#define _ERROR_		0
#define _SUCCESS_	1
#define TARGET_LEN	12

char* SetRequestMessage(char* typeMsg, int cardNumLen, char* cardNum, char* amount, char *code );
void DeleteCharOnString(char* str, char char2del);
char* StringPadding(char *strOrig, char ch2pad, int padlen);