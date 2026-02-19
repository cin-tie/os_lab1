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
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if(argc != 3){
		printf("Usage: creator <filename> <count>\n");
		return 1;
	}

	char* filename = argv[1];
	int count = atoi(argv[2]);
	
	FILE* file;
	file = fopen(filename, "wb");
	if(!file){
		printf("Cannot open file\n");
		return 1;
	}

	struct employee e;

	for(int i = 0; i < count; ++i){
		printf("Employee %d\n", i + 1);
		printf("Id: ");
		scanf("%d", &e.num);
		printf("Name: ");
		scanf("%9s", e.name);
		printf("Hours: ");
		scanf("%lf", &e.hours);

		fwrite(&e, sizeof(struct employee), 1, file);
	}

	fclose(file);

	return 0;
}
