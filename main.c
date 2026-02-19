#include <windows.h>
#include <stdio.h>

int main() {
	char binfile[100];
	int count;

	printf("Enter binary file name: ");
	scanf("%s", binfile);

	printf("Enter number of records: ");
	scanf("%d", &count);

	char cmdCreator[200];
	sprintf(cmdCreator, "creator.exe %s %d", binfile, count);

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if(!CreateProcess(NULL, cmdCreator, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)){
		printf("Failed to start Creator\n");
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	FILE* fileb;
       	fileb = fopen(binfile, "rb");

	struct employee{
		int num;
		char name[10];
		double hours;
	} e;

	if(!fileb){
		printf("Cannot open binary file\n");
		return 1;
	}

	printf("\nBinary file content:\n");
	while(fread(&e, sizeof(e), 1, fileb)){
		printf("%d %s %.2f\n", e.num, e.name, e.hours);
	}
	fclose(fileb);

	return 0;
}
