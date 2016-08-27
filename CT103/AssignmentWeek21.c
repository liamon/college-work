#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *getMonth(int month);
char *getYear(int year);
int hottestTemp(int argc, char *argv[]);
void saveFile(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	if (argc % 2 == 0) { // Checks
		puts("ERROR: Data entered incorrectly -- ending program");
		return 1;
	}

	saveFile(argc, argv);
	return 0;
}

char *getMonth(int month) {
	switch (month) {
		case 0: return "Jan";
		case 1: return "Feb";
		case 2: return "Mar";
		case 3: return "Apr";
		case 4: return "May";
		case 5: return "Jun";
		case 6: return "Jul";
		case 7: return "Aug";
		case 8: return "Sep";
		case 9: return "Oct";
		case 10: return "Nov";
		case 11: return "Dec";
		default: return "";
	}
}

char *getYear(int year) {
	year += 1900;
	char yearstr[5] = "";
	sprintf(yearstr, "%d", year);
	return yearstr;
}

int hottestTemp(int argc, char *argv[]) {
	double hottest = strtod(argv[2], NULL);
	int indexOfHottest = 2;
	// First temperature should be at argv[2]
	
	if (argc > 3) {
		for (int i = 4; i < argc; i += 2) {
			if (strtod(argv[i], NULL) > hottest) {
				hottest = strtod(argv[i], NULL);
				indexOfHottest = i;
			}
		}
	}
	return indexOfHottest;
}

void saveFile(int argc, char *argv[]) {
	time_t currtime;
	time(&currtime);
	struct tm *date = localtime(&currtime);

	char *month = getMonth(date->tm_mon);
	char day[3] = "";
	sprintf(day, "%d", date->tm_mday);
	char *year = getYear(date->tm_year);
	char datestr[12] = "";

	strcpy(datestr, month);
	strcat(datestr, " ");
	strcat(datestr, day);
	strcat(datestr, " ");
	strcat(datestr, year);
	
	char *filename = strcat(datestr, ".txt");
	FILE *fp = fopen(filename, "w+");
	int numReadings = (argc - 1) / 2;
	int i = 0; // pointer index value
	int j = 1; // argv index value

	for (; i < numReadings; i++, j += 2) {
		fprintf(fp, "%s\t%lf\n", argv[j], strtod(argv[j + 1], NULL));
	}

	int hottest = hottestTemp(argc, argv);
	fprintf(fp, "Hottest town on this day: %s (%lf)", argv[hottest - 1], strtod(argv[hottest], NULL));
	fclose(fp);
}