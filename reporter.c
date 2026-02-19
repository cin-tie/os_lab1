#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

struct employee{
	int num;
	char name[10];
	double hours;
};

int main(int argc, char* argv[]){
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if(argc != 4){
		printf("Usage: reporter <binfile> <reportfile> <rate>\n");
		return 1;
	}

	char* binfile = argv[1];
	char* reportfile = argv[2];
	double rate = atof(argv[3]);

	FILE* fileb;
	fileb = fopen(binfile, "rb");
	if(!fileb){
		printf("Cannot open binary file\n");
		return 1;
	}

	FILE* filer = fopen(reportfile, "w");
	if(!filer){
		printf("Cannot open report file\n");
		return 1;
	}

	fprintf(filer, "Отчет по файлу \"%s\"\n", binfile);
	fprintf(filer, "Num\tName\tHours\tSalary\n");

	struct employee e;

	while(fread(&e, sizeof(struct employee), 1, fileb)){
		double salary = e.hours * rate;
		fprintf(filer, "%d\t%s\t%.2f\t%.2f\n", e.num, e.name, e.hours, salary);
	}

	fclose(fileb);
	fclose(filer);

	return 0;
}
