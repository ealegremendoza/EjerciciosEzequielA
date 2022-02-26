#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define _TRUE_	1
#define _FALSE_	0
#define _ERROR_ 	0
#define _SUCCESS_ 	1
#define TARGET_LEN	10
#define PATH_CHARACTER_LIMIT	20


char allNumbers(char *str);
int checkFileName(char* path);
char* InputNameFile(void);
int inputNumbers(const char* inputMsg, char stopChar);
