int james_version = 4.0;

#define OUTPUT
char* output_log = "james-build-log.txt";

#include "include/emman.h"
#include "include/JamesFunctions.h" 

int main(int argc, char *argv[ ]){
	ClearPrints();
	DelFile(output_log);
	Compiler.clean = false;
	Compiler.syncdir = false;
	Compiler.shutdown = false;
	Compiler.push = false;
	#ifdef OUTPUT
	Compiler.args = "make otapackage -j7 | tee -a .james-build-log.txt";
	#else
	Compiler.args = "make otapackage -j7";
	#endif
	Compiler.upload = 0;
	Compiler.device = 0;
	for(tick = 1; tick < argc; tick++){
		if(CompareStrings(argv[tick], "--help") || CompareStrings(argv[tick], "-h")){
			PrintHelp();
			exit(0);
		}
	}
	if(argc <= 1){
		PrintText("Invalid parameters!");
		PrintText("Type James --help");
		exit(-1);
	}
	while(true){
		ClearPrints();
		PrintText("Please Enter your Product Device Name, eg: 'doubleshot' or 'ville'");
		Compiler.devicename = GetUserInput();
		ClearPrints();
		PrintTextWithString("Product Device Name: ", Compiler.devicename, "");
		PrintText("Correct? yes/no");
		text = GetUserInput();
		if(IsYes(text)) break;
	}
	for(tick = 1; tick < argc; tick++){
		if(CompareStrings(argv[tick], "--help") || CompareStrings(argv[tick], "-h")){
			PrintHelp();
			exit(0);
		}
		else{
			if(!Compiler.syncdir) Compiler.syncdir = CompareStrings(argv[tick], "-s");
			if(!Compiler.clean) Compiler.clean = CompareStrings(argv[tick], "-c");
			if(!Compiler.shutdown) Compiler.shutdown = CompareStrings(argv[tick], "-q");
			if(!Compiler.push) Compiler.push = CompareStrings(argv[tick], "-p");
			if(CompareStrings(argv[tick], "-d1")){
				Compiler.device = 1;
				Compiler.devicename = CombineStrings("cm_", Compiler.devicename);
			}
			else if(CompareStrings(argv[tick], "-d2")){
				Compiler.device = 2;
				Compiler.devicename = CombineStrings("aokp_", Compiler.devicename);
			}
			else if(CompareStrings(argv[tick], "-d3")){
				Compiler.device = 3;
				Compiler.devicename = CombineStrings("ev_", Compiler.devicename);
			}
			else if(CompareStrings(argv[tick], "-d4")){
				Compiler.device = 4;
				Compiler.devicename = CombineStrings("slim_", Compiler.devicename);
			}
			else if(CompareStrings(argv[tick], "-d5")){
				Compiler.device = 2;
				Compiler.devicename = CombineStrings("carbon_", Compiler.devicename);
			}
			if(CompareStrings(argv[tick], "-u1")) Compiler.upload = 1;
			else if(CompareStrings(argv[tick], "-u2")) Compiler.upload = 2;
		}
	}
	PrintArgs();
	PrintText("Press Enter to begin Building ...");
	WaitForEnterKey();
	CompileRom();
	return 0;
}
