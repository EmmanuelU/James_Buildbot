int james_version = 4.0;

#include "include/emman.h"
#include "include/JamesFunctions.h" 

int main(int argc, char *argv[ ]){
	ClearPrints();
	if(argc <= 1){
		PrintText("Invalid parameters!");
		PrintText("Type James --help");
		exit(-1);
	}

	for(tick = 1; tick < argc; tick++){
		printf ("Hello\n");
         	printf ("World\n");
		PrintVar(tick);
		if(CompareStrings(argv[tick], "--help") || CompareStrings(argv[tick], "-h")){
			PrintHelp();
			exit(0);
		}
		else{
			if(!syncdir) syncdir = CompareStrings(argv[tick], "-s");
			if(!clean) clean = CompareStrings(argv[tick], "-c");
			if(!shutdown) shutdown = CompareStrings(argv[tick], "-q");
			if(!push) push = CompareStrings(argv[tick], "-p");
			if(CompareStrings(argv[tick], "-d1")) device = 1;
			else if(CompareStrings(argv[tick], "-d2")) device = 2;
			else if(CompareStrings(argv[tick], "-d3")) device = 3;
			else if(CompareStrings(argv[tick], "-d4")) device = 4;
			else if(CompareStrings(argv[tick], "-d5")) device = 5;
			if(CompareStrings(argv[tick], "-u1")) upload = 1;
			else if(CompareStrings(argv[tick], "-u2")) upload = 2;
		}
	}
	PrintArgs();
	sleep(2);
	system("logcat");
	return 0;
}
