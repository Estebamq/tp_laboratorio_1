#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int isValidName(char* stringRecibido);

int getUnsignedInt(char* msg,char* msgError,int minSize,int maxSize,int reintentos,int* input);
int isValidNumber(char* stringRecibido);

int getFloat(char* msg, char* msgError, int minSize, int maxSize, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);



