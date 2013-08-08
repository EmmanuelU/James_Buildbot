bool clean = false,
	syncdir = false,
	shutdown = false,
	push = false;

int upload = 0;
int device = 0;

void PrintHelp(){
	ClearPrints();
	PrintTextWithVar("James BuildBot v", james_version, ":");
	PrintText("Usage: ./James -[OPTIONS]"); 
	SkipLine();
	PrintText("Options:"); 
	SkipLine();
	PrintText("[-h] - Show this message");
	SkipLine();
	PrintText("[-s] - Sync the repo before building");
	SkipLine();
	PrintText("[-c] - Clean the enviroment before building");
	SkipLine();
	PrintText("[-q] - Shutdown Computer after Build");
	SkipLine();
	PrintText("[-p] - Push Rom to Device after Build");
	SkipLine();
	SkipLine();
	PrintText("Device Naming:");	
	SkipLine();
	PrintText("	[-d1] - CyanogenMod");
	SkipLine();
	PrintText("	[-d2] - AOKP");
	SkipLine();
	PrintText("	[-d3] - Evervolv");
	SkipLine();
	PrintText("	[-d4] - Slim Roms");
	SkipLine();
	PrintText("	[-d5] - CarbonDev");
	SkipLine();
	SkipLine();
	PrintText("Upload build to FTP Server:");	
	SkipLine();
	PrintText("	[-u1] - Upload a Nightly");
	SkipLine();
	PrintText("	[-u2] - Upload a Stable Release");
	SkipLine();
	PrintText("Example: ./James -s -c -u1 -d3");
	SkipLine();
	return;
}

void PrintArgs(){
	ClearPrints();
	PrintTextWithVar("James BuildBot v", james_version, ":");
	SkipLine();
	PrintTextWithVar("Sync Repo: ", syncdir, "");
	SkipLine();
	PrintTextWithVar("Clean Repo: ", clean, "");
	SkipLine();
	PrintTextWithVar("Shutdown after Completion: ", shutdown, "");
	SkipLine();
	PrintTextWithVar("Push to Device after Completion: ", push, "");
	SkipLine();
	PrintTextWithVar("Device Selection: ", device, "");
	SkipLine();
	PrintTextWithVar("Upload Selection: ", upload, "");
	SkipLine();
	return;
}
