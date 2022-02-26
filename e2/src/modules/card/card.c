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

		card.label[0]=index+'0';
		fwrite(card.label, sizeof(char), strlen(card.label)+1, fp);
		card.id=index;
		fwrite(&card.id, sizeof(int),1, fp);
	}
	fclose(fp);
	return fileGenStatus;
}
