#include "sockets.h"

char* SetRequestMessage(char* typeMsg, int cardNumLen, char* cardNum, char* amount, char *code ){
	char *RequestMessage;
	char *AmountPadded;
	int lenMsg=0;
	char ascCardNumLen[TYPE_MSG_LEN+1];

	// conviene preparar primero el monto
	DeleteCharOnString(amount,'.');
	AmountPadded=(char*)malloc(sizeof(char)*(TARGET_LEN+1));
	if(NULL==AmountPadded){
		printf("Error. No se pudo pedir memoria para AmountPadded.\n\n");
		return (char*)NULL;
	}


	AmountPadded=StringPadding(amount,'0',TARGET_LEN);



	sprintf(ascCardNumLen,"%d",cardNumLen);
	lenMsg+=strlen(typeMsg);
	lenMsg+=strlen(ascCardNumLen);
	lenMsg+=strlen(cardNum);
	lenMsg+=strlen(AmountPadded);
	lenMsg+=strlen(code);
	lenMsg+=1; //por el null


	RequestMessage=(char*)malloc(sizeof(char)*lenMsg);
	if(NULL==RequestMessage){
		printf("Error. No se pudo pedir memoria para RequestMessage.\n\n");
		return (char*)NULL;
	}

	sprintf(RequestMessage,"%s%s%s%s%s",typeMsg,ascCardNumLen,cardNum,AmountPadded,code);
	free(AmountPadded);
	return RequestMessage;
}


void DeleteCharOnString(char* str, char char2del){
	int indexOrig=0;
	int indexDest=0;
	char *strAuxOrig;
	char *strAuxDest; 
	int lenstr=strlen(str);
	strAuxOrig=(char*) malloc(sizeof(char)*(lenstr+1));
	strAuxDest=(char*) malloc(sizeof(char)*(lenstr+1));
	strcpy(strAuxOrig,str);

	for(indexOrig=0;indexOrig<lenstr;indexOrig++){
		if(strAuxOrig[indexOrig]==char2del){
			//indexDest-=1;
		}
		else{
			strAuxDest[indexDest]=strAuxOrig[indexOrig];
			indexDest+=1;		
		}
		
	}
	strAuxDest[lenstr-1]='\0';

	strcpy(str,strAuxDest);
	free(strAuxDest);
	free(strAuxOrig);
}

char* StringPadding(char *strOrig, char ch2pad, int padlen){
	char *outStringPadded;
	char *padding;
	
	outStringPadded=(char*)malloc(sizeof(char)*(padlen+1));
	padding=(char*)malloc(sizeof(char)*(padlen+1));
	
	memset(padding,'0',padlen);
  	padding[padlen] = '\0';
  	
  	padlen-=strlen(strOrig);
  	if(padlen < 0) padlen = 0;

  	sprintf(outStringPadded,"%*.*s%s",padlen,padlen,padding,strOrig);
  	free(padding);
	return outStringPadded;

}

/**
* Crea un socket
* @return handle del socket o -1 en caso de error
*/
int socketCreate(){
	return _SOCKET_SUCCESS_;
}

/**
* Conectar el socket a un host
* @param handle handle del socket a utilizar
* @param ip direccion ip del host a conectarse
* @param port puerto del host a conectarse
* @return handle del socket o -1 en caso de error
*/
int socketConnect(int handle, const char *ip, unsigned short port){
	return _SOCKET_SUCCESS_;
}

/**
* Leer datos del socket. La función bloquea hasta leer datos o transcurrir maxTimeout milisegundos
* @param handle handle del socket a utilizar
* @param data puntero donde se guardarán los datos leidos
* @param maxTimeout tiempo máximo de espera en milisegundos
* @return cantidad de bytes leidos o -1 en caso de error
*/
int socketRead(int handle, unsigned char *data, int maxTimeout){
#if TESTING_SOCKET_READ == REJECT
	strcpy(data,"021002");
#elif TESTING_SOCKET_READ == VALIDATE
	strcpy(data,"021000");
#else
	printf("Error.\n");
#endif
	printf("read data:%s\n",data);

#if TESTING_SOCKET_TIMEOUT == CONNECTION_ERROR
	return _SOCKET_ERROR_;
#else
	return strlen(data);
#endif
}

/**
* Escribir datos en un socket.
* @param handle handle del socket a utilizar
* @param data puntero donde se leerán los datos a escribir
* @return cantidad de bytes escritos o -1 en caso de error
*/
int socketWrite(int handle, const unsigned char *data){
	return _SOCKET_SUCCESS_;
}

/**
* Cierra el socket y libera recursos.
* @param handle handle del socket a utilizar
* @return 0 en caso de exito o -1 en caso de error
*/
int socketClose(int handle){
	return _SOCKET_SUCCESS_;
}



int ValidateCard(const char *ip, unsigned short port,char* typeMsg, int cardNumLen,
				 char* cardNum, char* amount, char *code,int maxResponseTimeout){
	
	char *RequestMessage;
	char ResponseMessage[6+1];
	int sockfd;
	int connectionStatus=_SOCKET_SUCCESS_;

	RequestMessage= SetRequestMessage(	typeMsg,
										cardNumLen,
										cardNum,
										amount,
										code);
	if(NULL==RequestMessage){
		printf("> Error. No pudo completarse la operación.\n");
		return _SOCKET_ERROR_;
	}

	printf("RequestMessage: %s\n",RequestMessage);


	/*ACA LLAMAR A SOCKET*/

	sockfd=socketCreate();
	if(_SOCKET_SUCCESS_ ==sockfd){

		if(_SOCKET_SUCCESS_==socketConnect(sockfd,ip,port)){
			if(_SOCKET_ERROR_ != socketWrite(sockfd,RequestMessage)){
				if(_SOCKET_ERROR_ !=socketRead(sockfd, ResponseMessage, maxResponseTimeout )) {
					if(VALID_CODE==GetCodeFromResponseMessage(ResponseMessage)){
						printf("APROBADA\n");
					}
					else
						printf("RECHADAZA\n");

				}
				else
					connectionStatus=_SOCKET_ERROR_;
			}
			else
				connectionStatus=_SOCKET_ERROR_;

		}
		else
			connectionStatus=_SOCKET_ERROR_;

	}
	else
		connectionStatus=_SOCKET_ERROR_;

	if(_SOCKET_ERROR_==connectionStatus)
		printf("ERROR EN LA COMUNICACION\n");

	free(RequestMessage);
	return connectionStatus;
}



int GetCodeFromResponseMessage(char* ResponseMessage){

	int respMsgLen=0;
	int respMsgCode=0;
	char ascRespMsgCode[RESPONSE_MENSSAGE_CODE_LEN+1];
	printf("ResponseMessage: %s\n",ResponseMessage);
	if(_ERROR_ ==IsStringOnlyNumbers(ResponseMessage)){
		printf("> Error. El mensaje de respuesta solo puede contener numeros.\n");
		return -1;
	}
	respMsgLen=strlen(ResponseMessage);

	if(RESPONSE_MENSSAGE_LEN !=respMsgLen){
		printf("> Error. El mensaje de respuesta solo puede contener 4 digito.\n");
		return -1;
	}

	ascRespMsgCode[0]=ResponseMessage[4];
	ascRespMsgCode[1]=ResponseMessage[5];
	ascRespMsgCode[2]='\0';

	respMsgCode=atoi(ascRespMsgCode);
	printf("codigo: %d\n",respMsgCode);
	return respMsgCode;
}