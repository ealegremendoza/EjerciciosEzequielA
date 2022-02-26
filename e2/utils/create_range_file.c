#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// gcc create_range_file.c -o crf.o -Wall -g
#define NREGISTERS	1
typedef struct {
  char rangeLow[8+1];
  char rangeHigh[8+1];
  unsigned char len;
  int id;
} range_t;


int main(void){ 

	range_t range;
	FILE *fp;
	int index=0;
	strcpy(range.rangeLow,"00000000");
	strcpy(range.rangeHigh,"11111111");
	range.len=14;
	range.id=1;

	printf("%d\n",range.len);


	fp = fopen("./ranges.dat", "wb");

	if(fp == NULL) {
		printf("No se pudo abrir el archivo... \n"); return -1; 
	}


	for(index=0;index<NREGISTERS;index++,range.id++, range.len++){
		range.rangeLow[0]=index+'0';
		fwrite(range.rangeLow, sizeof(char), strlen(range.rangeLow)+1, fp);
		
		range.rangeHigh[0]=index+1+'0';
		fwrite(range.rangeHigh, sizeof(char), strlen(range.rangeLow)+1, fp);
		
		fwrite(&range.len,sizeof(unsigned char),1,fp);
		
		fwrite(&range.id,sizeof(int),1,fp);
    printf("len %ld\n",sizeof(range));
	}

	fclose(fp);
	return(0);
}


/*int main(void){ 

  range_t range;
  FILE *fp;

  strcpy(range.rangeLow,"00000000");
  strcpy(range.rangeHigh,"11111111");
  range.len=14;
  range.id=1;

  printf("%d\n",range.len);
  

  fp = fopen("./ranges.dat", "wb");

  if(fp == NULL) {
    printf("No se pudo abrir el archivo... \n"); return -1; 
  }

  // Escribimos 1 registro de tipo struct formulario
  fwrite(range.rangeLow, sizeof(char), strlen(range.rangeLow)+1, fp);
  fwrite(range.rangeHigh, sizeof(char), strlen(range.rangeLow)+1, fp);

  fwrite(&range.len,sizeof(unsigned char),1,fp);
  fwrite(&range.id,sizeof(int),1,fp);

  fclose(fp);
  return(0);
}*/
