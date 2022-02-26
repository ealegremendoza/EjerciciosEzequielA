#include "inputFunctions.h"

char* RequestPurchaseAmount(void) {
	char inputAmount[MAX_LEN_STR];
	char *filteredAmount;
	int approvedText=_ERROR_;
	float numberAmount=0.0;
	int checkStatus=_ERROR_;
	//const char *padding="000000000000";
	//int padLen=0;
	//char ascAmount[AMOUNT_SIZE+1];

	filteredAmount=(char*)malloc(sizeof(char)*(AMOUNT_SIZE+1));
	if(NULL==filteredAmount){
		printf("> Error. Memoria insuficiente para crear filteredAmount.\n");
		return NULL;
	}
	 
	do{
	 	printf("> Ingrese el monto de compra:\n$");
	 	scanf("%s",inputAmount);
	 	if(strlen(inputAmount)>(AMOUNT_SIZE)){
	 		// ERROR, Se aceptan 12 digitos como máximo.
	 		approvedText=_ERROR_;
	 		printf("> Error. Se aceptan 12 digitos como máximo.\n");
	 		continue;
	 	}
	 	/*no permito que ponga el caracter pesos*/
	 	checkStatus=IsAPositiveDecimalNumber(inputAmount);

	 	if(_SUCCESS_== checkStatus){
	 		/*es un numero decimal positivo*/
	 		/*convierto el numero de cadena de caracteres al formato deseado*/
	 		numberAmount=atof(inputAmount);
			sprintf(filteredAmount,"%.2f",numberAmount);
	 		//padLen=AMOUNT_SIZE - strlen(ascAmount);
	 		//if(padLen < 0) padLen = 0;
	 		//sprintf(filteredAmount,"%*.*s%s",padLen,padLen,padding,ascAmount);
	 		approvedText=_SUCCESS_;
	 	}
	 	else{
	 		/* no es un numero*/
	 		approvedText=_ERROR_;
	 		printf("> Error. Ingrese sólo números decimales positivos.\n\n");
	 	}


	}while(_SUCCESS_ != approvedText);


	return filteredAmount;
}


/*	brief: Verifica si todos los caracteres de la cadena corresponden a números decimales positivos 
	@param str, en este puntero la cadena de caracteres.
	@return  __TRUE__ (1) por exito, __FALSE__(0) por error.
*/
int IsAPositiveDecimalNumber(char *inputString){
	int count=0;
	int index;
	int dpCount=0;
	int dpPosition=0;
	int charCount=0;


	// Reviso cuantos puntos decimales introdujo el usuario.
	for(index=0;index<strlen(inputString);index++){
		if(inputString[index]=='.'){
			dpCount+=1;
			dpPosition=index;
		}
	}

	// Si hay más de un punto decimal.
	if(dpCount>1){
		/* ERROR */
		return _ERROR_;
	}

	// A este punto solo puede haber como mucho un solo punto decimal o no haber.
	// El resto deben ser numeros positivos porque no se puede pagar algo negativo.
	for(index=0;index<strlen(inputString);index++){
		if((inputString[index]>='0'&& inputString[index]<='9') || (inputString[index]=='.'))
			charCount++;
	}

	return (strlen(inputString)==charCount) ? _SUCCESS_:_ERROR_;
}




char* RequestCardNumber(void){

	 char inputCardNumber[MAX_LEN_STR];
	 char *filteredCardNumber;
	 int approvedText=_ERROR_;
	 unsigned long int cardNumb=0;
	 //const char *padding="000000000000";
	 int checkStatus=_ERROR_;
	 int inputCardNumberLen=0;
	 filteredCardNumber=(char*)malloc(sizeof(char)*(MAX_LEN_CARD_NUMBER+1));
	 
	 do{
	 	printf("> Ingrese el número de la tarjeta:\n");
	 	scanf("%s",inputCardNumber);
	 	
	 	inputCardNumberLen=strlen(inputCardNumber);
	 	if(inputCardNumberLen< MIN_LEN_CARD_NUMBER || inputCardNumberLen > MAX_LEN_CARD_NUMBER ){
	 		approvedText=_ERROR_;
	 		printf("> Error. Cantidad de digitos incorrecta.\n");
	 		continue;
	 	}
	 	/*no permito que ponga el caracter pesos*/
	 	checkStatus=IsStringOnlyNumbers(inputCardNumber);
		
	 	if(_SUCCESS_== checkStatus){
	 		/*es un numero entero positivo*/
	 		/*convierto el numero de cadena de caracteres al formato deseado.*/
	 		strcpy(filteredCardNumber,inputCardNumber);
	 		approvedText=_SUCCESS_;
	 	}
	 	else{
	 		/* no es un numero*/
	 		approvedText=_ERROR_;
	 		printf("> Error. Ingrese sólo números enteros positivos.\n\n");
	 	}


	 }while(_SUCCESS_ != approvedText);

	 
	 return filteredCardNumber;
}

/*	brief: Verifica si todos los caracteres de la cadena corresponden a números. 
	@param str, en este puntero la cadena de caracteres.
	@return  __TRUE__ (1) por exito, __FALSE__(0) por error.
*/
char IsStringOnlyNumbers(char *str){
	int count=0;
	int i;
	for(i=0;i<strlen(str);i++){
		if(str[i]>='0' && str[i]<='9')
			count++;
	}	
	return  (count==strlen(str)) ? _SUCCESS_:_ERROR_;
}


char* RequestCardSecurutyCode(void){

	 char inputCardSecurityCode[MAX_LEN_STR];
	 char *filteredSecurityCode;
	 int approvedText=_ERROR_;
	 int cardCode=0;
	 int checkStatus=_ERROR_;
	 int inputCardSecurityCodeLen=0;
	 int indexCardCode=0;


	 filteredSecurityCode=(char*)malloc(sizeof(char)*(SECURITY_CODE_LEN+1));
	 if(NULL==inputCardSecurityCode){
	 	printf("Error. No pudo solicitarse memoria para char* inputCardSecurityCode.\n\n");
	 	return NULL;
	 }
	 
	 do{
	 	printf("> Ingrese el código de seguridad de la tarjeta:\n");
	 	scanf("%s",inputCardSecurityCode);
	 	
	 	inputCardSecurityCodeLen=strlen(inputCardSecurityCode);
	 	if(inputCardSecurityCodeLen!= SECURITY_CODE_LEN ){
	 		// ERROR, Se aceptan 3 digitos solamente.
	 		approvedText=_ERROR_;
	 		printf("> Error. Cantidad de digitos incorrecta.\n\n");
	 		continue;
	 	}

	
	 	checkStatus=IsStringOnlyNumbers(inputCardSecurityCode);
		
	 	if(_SUCCESS_== checkStatus){
	 		/*es un numero entero positivo*/
	 		/*convierto el numero de cadena de caracteres al formato deseado.*/
	 		
	 		for(indexCardCode=0;indexCardCode<SECURITY_CODE_LEN;indexCardCode++){
	 			filteredSecurityCode[indexCardCode]=inputCardSecurityCode[indexCardCode];
	 		}
	 		filteredSecurityCode[SECURITY_CODE_LEN]='\0';
	 		approvedText=_SUCCESS_;
	 	}
	 	else{
	 		/* no es un numero*/
	 		approvedText=_ERROR_;
	 		printf("> Error. Ingrese sólo números enteros positivos.\n\n");
	 	}


	 }while(_SUCCESS_ != approvedText);

	 
	 return filteredSecurityCode;
}

