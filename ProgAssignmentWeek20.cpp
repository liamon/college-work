#include "stdafx.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkArgs(char *arg, int argc, char **argv);

void lines(FILE *fp);
void bytes(FILE *fp);
void chars(FILE *fp);

int main(int argc, char **argv) {
	FILE *textfile = fopen(argv[1], "r");
	if (textfile == NULL) {
		puts("Error opening file -- exiting!");
	}
	if (checkArgs("/l", argc, argv)) {
		lines(textfile);
	}
	if (checkArgs("/s", argc, argv)) {
		bytes(textfile);
	}
	if (checkArgs("/c", argc, argv)) {
		chars(textfile);
	}
	return 0;
}

bool checkArgs(char *arg, int argc, char **argv) {
	switch (argc) {
		case 3:
			if (!strcmp(argv[2], arg)) {
				return true;
			}
			return false;
		case 4:
			if (!strcmp(argv[2], arg) || !strcmp(argv[3], arg)) {
				return true;
			}
			return false;
		case 5:
			if (!strcmp(argv[2], arg) || !strcmp(argv[3], arg) || !strcmp(argv[4], arg)) {
				return true;
			}
			return false;
	}
}

void lines(FILE *fp) {
	unsigned long long lines = 0; // All these indexes are unsigned long long to ensure they can handle files as big as possible
	char test = getc(fp);
	while (test  != EOF) {
		if ('\n' == test) {
			++lines; 
		}
		test = getc(fp);
	} // I decided to count it with getc instead of with fgets as this way allows for the lines to be any length
	
	++lines; // Need to increment this as there is no newline at the end of the last line
	printf("#lines = %llu\n", lines);
}

void bytes(FILE *fp) {
	unsigned long long bytes = 0;
	rewind(fp); // Need to include this in the remaining functions else fp will be at EOF and the while loops will not run
	char test = getc(fp);
	while (test != EOF) {
		++bytes;
		test = getc(fp);
	}
	printf("size = %llu bytes\n", bytes);
}

void chars(FILE *fp) {
	unsigned long long chars = 0;
	rewind(fp);
	char test = getc(fp);
	while (test != EOF) {
		if ('\n' != test) {
			++chars;
		}
		test = getc(fp);
	}
	printf("#chars = %llu\n", chars);
}
