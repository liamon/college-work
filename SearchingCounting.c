#include "stdafx.h"
#include <stdio.h>
#include <string.h>

#define SIZE 100

void search(char name[]);

char surname[SIZE][12]; // This needs to be a global variable so both main and search can access it

int main(void) {
	FILE *surnames;
	int i = 0;
	char nameToFind[12];
	
	fopen_s(&surnames, "C:/Users/Liam/Downloads/surnames.txt", "r");
	if (surnames == NULL) { // Test if the file was able to open properly
		puts("Error opening file.");
		return 1;
	}
	while (i < SIZE) {
		fscanf_s(surnames, "%s", surname[i++], 11);
	}
	fclose(surnames); // No longer need surnames.txt so I can close it
	
	printf("Enter a surname to find: ");
	scanf_s("%s", nameToFind, 11);
	search(nameToFind);
    return 0;
}

void search(char name[]) {
	int i = 0;
	int count = 0;
	
	while (i < SIZE) {
		if (!strcmp(name, surname[i])) { // strcmp returns 0 if they are equal so this must be negated to make it true
			count++;
		}
		i++;
	}
	
	if (count) { // If count = 0 it will evaluate as false and will skip the first printf
		printf("The surname %s occurs in the file %d time(s).\n", name, count);
	}
	else {
		printf("The surname %s does not occur in the file.\n", name);
	}
}
