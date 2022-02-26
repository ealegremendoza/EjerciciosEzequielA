#include "card.h"

int genRangesFile(const char *path){
	int fileGenStatus=_ERROR_
	range_t range;
	FILE *fp;
	int index=0;

	memset(range.rangeHigh,'1',RANGE_DIGITS);
	memset(range.rangeLow,'0',RANGE_DIGITS);
	
	range.rangeHigh[RANGE_DIGITS]='\0';
	range.rangeLow[RANGE_DIGITS]='\0';

	range.len=(unsigned char) MIN_CARD_DIGITS;
	range.id=MIN_ID;

	fp=fopen(PATH_RANGES,"wb");
	if(NULL==fp){
		printf("Error. No se pudo crear el archivo.\n");
		fileGenStatus=_ERROR_;
	}

	fileGenStatus=_SUCCESS_;

	for(index=0;index<NUM_RANGE_REGS;index++){

		range.rangeLow[0]=index+'0';
		fwrite(range.rangeLow, sizeof(char), strlen(range.rangeLow)+1, fp);
		
		range.rangeHigh[0]=index+1+'0';
		fwrite(range.rangeHigh, sizeof(char), strlen(range.rangeLow)+1, fp);
		
		fwrite(&range.len,sizeof(unsigned char),1,fp);
		
		fwrite(&range.id,sizeof(int),1,fp);

   		range.len++;
   		range.id++;
	}
	fclose(fp);
	return fileGenStatus;
}

int genCardsFile(const char *path){
	int fileGenStatus=_ERROR_
	card_t card;
	FILE *fp;
	int index=0;

	strcpy(card.label,"tarjeta_0");

	fp=fopen(PATH_CARDS,"wb");
	if(NULL==fp){
		printf("Error. No se pudo crear el archivo.\n");
		fileGenStatus=_ERROR_;
	}

	fileGenStatus=_SUCCESS_;

	for(index=0;index<NUM_CARD_REGS;index++){

		card.label[8]=index+'0';
		card.id=index;
		fwrite(card.label, sizeof(char), strlen(card.label)+1, fp);
		fwrite(&card.id, sizeof(int),1, fp);
	}
	fclose(fp);
	return fileGenStatus;
}

int readRangesFile(const char *path, const char *ascCardNum){
	range_t range;
	FILE *fp;
	char ascCardCode[RANGE_DIGITS+1];
	int indexCardCode;
	
	// Copio los primeros ocho digitos del número de tarjeta
	for(indexCardCode=0;indexCardCode<RANGE_DIGITS;indexCardCode++){
		ascCardCode[indexCardCode]=ascCardNum[indexCardCode];
	}
	ascCardCode[RANGE_DIGITS]='\0';

	// Abro el archivo
	fp=fopen(path,"rb");
	if(NULL==fp){
		printf("Error. No se pudo abrir el archivo.\n");
		return -1;
	}
	// Hago un barrido por los registros buscando el que cumple con los requisitos
	while(!feof(fp)){
		fread(range.rangeLow, sizeof(char), RANGE_LOW+1, fp);
		fread(range.rangeHigh, sizeof(char), RANGE_HIGH+1, fp);
		fread(&range.len, sizeof(unsigned char),1, fp);
		fread(&range.id, sizeof(int),1, fp);
		
		if(IsCardCodeinRange(ascCardCodeC,range)){
			//estoy en rango
			if(IsCardNumLenghtMatches(ascCardNum,range)){
				// encontré el registro, retornar id
				fclose(fp);
				return range.id;
			}
		}// si no está dentro del rango en este registro continuo leyendo el siguiente

	}
	// Si llegué hasta aqui es que no encontré registro alguno que cumpla con los requisitos
	fclose(fp);
	return INVALID_ID;
}

int IsCardCodeinRange(const char* ascCardCode, range_t range){
	int inputCardCode=0;
	int inputRangeLow=0;
	int inputRangeHigh=0;

	inputCardCode=atoi(ascCardCode);
	inputRangeLow=atoi(range.rangeLow);
	inputRangeHigh=atoi(range.rangeHigh);

	return  ((inputCardCode>=inputRangeLow)&&(inputCardCode<=inputRangeHigh)) ? _SUCCESS_:_ERROR_;
}


int IsCardNumLenghtMatches(const char* ascCardNum, range_t range){
	return (strlen(ascCardNum)==range.len)? _SUCCESS_:_ERROR_;
}

int readCardsFile(const char *path, const int cardId){
	range_t card;
	FILE *fp;

	fp=fopen(path,"rb");
	if(NULL==fp){
		printf("Error. No se pudo abrir el archivo.\n");
		return -1;
	}

	while(!feof(fp)){
		fread(card.label, sizeof(int),1, fp);
		fread(&card.id, sizeof(int),1, fp);
		if(CardIdMatches){
			// Encontré la tarjeta
			printf("> %s\n",card.label);
			fclose(fp);
			return _SUCCESS_;
		}
		// si el ID con coincide con el de este registro continuo leyendo el siguiente
	}
	// Si llegué hasta aqui es que no encontré registro alguno que cumpla con los requisitos
	fclose(fp);
	return _ERROR_;
}

int CardIdMatches(int cardId,card_t card){
	return (cardId==card.id)?_SUCCESS_:_ERROR_;
}