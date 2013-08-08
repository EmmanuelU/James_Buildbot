#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 
#include <stdint.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int tick;

char* text;

void ClearPrints(){
	printf("\033c");
	return;
}

void SkipLine(){
	printf("\n");
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

void PrintVar(int var){
	unsigned char string = var;
	fprintf(stdout, "%d\n", string);
	return;
}

bool CompareStrings(char* text, char* text2){
	return !strcmp(text, text2);
}

char* CombineStrings(char* text, char* text2){
	asprintf(&text, "%s%s", text, text2);
	return text;
}

char* GetUser(){
	return getenv("USER");
}

char* GetDir(){
	return getenv("PWD");
}

bool DoesDirExist(char* text){
	struct stat dir;
	tick = stat(text, &dir);
	if(-1 == tick) {
		if(ENOENT == errno) return false;
		else {
			perror("stat");
			exit(1);
		}
	} else return S_ISDIR(dir.st_mode);
}

bool DoesFileExist(char* text){
	struct stat dir;
	tick = stat(text, &dir);
	if(-1 == tick) {
		if(ENOENT == errno) return false;
		else {
			perror("stat");
			exit(1);
		}
	} else return !S_ISDIR(dir.st_mode);
}
