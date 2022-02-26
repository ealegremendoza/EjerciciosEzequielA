#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN_STR	100
#define AMOUNT_SIZE	(12) 
#define _ERROR_		0
#define _SUCCESS_ 	1

#define MIN_LEN_CARD_NUMBER	13
#define MAX_LEN_CARD_NUMBER	20

#define SECURITY_CODE_LEN	3


int IsAPositiveDecimalNumber(char *inputString);
char* RequestPurchaseAmount(void);
char* RequestCardNumber(void);
char IsStringOnlyNumbers(char *str);
char* RequestCardSecurutyCode(void);
