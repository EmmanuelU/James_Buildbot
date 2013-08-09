typedef struct James {
	
	bool clean;
	bool syncdir;
	bool shutdown;
	bool push;
	char* args;
	int upload;
	int device;
	char* devicename;

} James;

James Compiler;

void PrintHelp(){
	ClearPrints();
	PrintTextWithVar("James BuildBot v", james_version, ":");
	PrintText("Usage: ./James -[OPTIONS]"); 
	LineSkip();
	PrintText("Options:"); 
	LineSkip();
	PrintText("[-h] - Show this message");
	LineSkip();
	PrintText("[-s] - Sync the repo before building");
	LineSkip();
	PrintText("[-c] - Clean the enviroment before building");
	LineSkip();
	PrintText("[-q] - Shutdown Computer after Build");
	LineSkip();
	PrintText("[-p] - Push Rom to Device after Build");
	LineSkip();
	LineSkip();
	PrintText("Device Naming:");	
	LineSkip();
	PrintText("	[-d1] - CyanogenMod");
	LineSkip();
	PrintText("	[-d2] - AOKP");
	LineSkip();
	PrintText("	[-d3] - Evervolv");
	LineSkip();
	PrintText("	[-d4] - Slim Roms");
	LineSkip();
	PrintText("	[-d5] - CarbonDev");
	LineSkip();
	LineSkip();
	PrintText("Upload build to FTP Server:");	
	LineSkip();
	PrintText("	[-u1] - Upload a Nightly");
	LineSkip();
	PrintText("	[-u2] - Upload a Stable Release");
	LineSkip();
	LineSkip("Example: ./James -s -c -u1 -d3");
	LineSkip();
	return;
}

void PrintArgs(){
	ClearPrints();
	PrintTextWithVar("James BuildBot v", james_version, " Build Info:");
	LineSkip();
	PrintTextWithVar("Syncing Repo: ", Compiler.syncdir, "");
	LineSkip();
	PrintTextWithVar("Cleaning Repo: ", Compiler.clean, "");
	LineSkip();
	PrintTextWithVar("Shutdown after Compilation: ", Compiler.shutdown, "");
	LineSkip();
	PrintTextWithVar("Push to Device after Compilation: ", Compiler.push, "");
	LineSkip();
	PrintTextWithVar("Device Style Selection: ", Compiler.device, "");
	LineSkip();
	PrintTextWithString("Device Product: ", Compiler.devicename, "");
	LineSkip();
	PrintTextWithVar("Uploading: ", Compiler.upload, "");
	LineSkip();
	return;
}

void CompileRom(){
	ClearPrints();
	if(!DoesDirExist("build")){
		PrintText("No Build directory found!");
		quit();
	}
	system("bash build/envsetup.sh");
	text = CombineStrings("lunch ", Compiler.devicename);
	text = CombineStrings(text, "-userdebug");
	PrintText(text);
	system(text);
	system("make otapackage -j8");
	sleep(WAIT);

}
