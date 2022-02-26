#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE_LOW 8
#define RANGE_HIGH 8

typedef struct {
  char rangeLow[8+1];
  char rangeHigh[8+1];
  unsigned char len;
  int id;
} range_t;

int main(void){
	range_t range;
	FILE *fp;

	fp=fopen("./ranges.dat","rb");
	if(NULL==fp){
		printf("Error. No se pudo abrir el archivo.\n");
		return -1;
	}
	while(!feof(fp)){
		fread(range.rangeLow, sizeof(char), RANGE_LOW+1, fp);
    fread(range.rangeHigh, sizeof(char), RANGE_HIGH+1, fp);
    fread(&range.len, sizeof(unsigned char),1, fp);
    fread(&range.id, sizeof(int),1, fp);

 		printf("RangoL: %s\n", range.rangeLow);
 		printf("RangoH: %s\n", range.rangeHigh);
  	printf("Len: %d\n", range.len);
  	printf("id: %d\n",range.id);
	}

	fclose(fp);
	return 0;
}


/*
int main (void){
	range_t range;
	FILE *fp;
	fp = fopen("./ranges.dat", "rb");
	if(fp == NULL) {
    	printf("No se pudo abrir el archivo... \n"); return -1; 
 	}
 	//leo 1 registro
 	fread(&range, sizeof(range_t), 1, fp);

 	printf("RangoL: %s\n", range.rangeLow);
 	printf("RangoH: %s\n", range.rangeHigh);
  	printf("Len: %d\n", range.len);
  	printf("id: %d\n",range.id);

  	free(fp);
	return 0;
}
*/