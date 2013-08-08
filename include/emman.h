#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ClearPrints(){
	printf("\033c");
	return;
}

void PrintText(char* text){
	fprintf(stdout, "%s \n", text);
	return;
}

void PrintTextWithString(char* text, char* textvar, char* text2){
	fprintf(stdout, "%s%s%s\n", text, textvar, text2);
	return;
}

void PrintTextWithVar(char* text, int var, char* text2){
	unsigned char string = var;
	fprintf(stdout, "%s", text);
	fprintf(stdout, "%d", string);
	fprintf(stdout, "%s\n", text2);
	return;
}
