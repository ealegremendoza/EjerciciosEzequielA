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