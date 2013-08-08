#include "include/emman.h"
#include "include/JamesFunctions.h"
 
char* james_version = "4.0";

int main(int argc, char *argv[ ]){
	ClearPrints();
	PrintTextWithString("James BuildBot v", james_version, ":");
	if(argc < 2){
		PrintText("Invalid parameters!");
		PrintText("Type James --help");
		exit(-1);
	}
	return 0;
}
