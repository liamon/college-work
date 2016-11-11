#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int year;
	double price[12];
	double average;
} oil;

void printChoices();
oil *getOilData(oil *oilData);
double averagePrice(double *prices);
void highestPrice(oil *oilData);
void highestAvgPrice(oil *oilData);
int countYears();
char *getMonth(int month);

int yearcount = countYears(); // Global variable

int main(void) {
	int choice = 0;
	oil *oilData = malloc(sizeof(oil) * yearcount);
	// In my original answer to this question, I had (oil *) before the malloc but this is only required in C++ code.
	getOilData(oilData);
	printChoices();
	scanf("%d", &choice);


	while (choice) { // This will be true as long as choice != 0
		switch (choice) {
		case 1:
			highestPrice(oilData);
			break;
		case 2:
			highestAvgPrice(oilData);
			break;
		default:
			puts("\nInvalid input.\n");
			break;
		}
		printChoices();
		scanf("%d", &choice);
	}
	return 0;
}

void printChoices() {
	printf("Enter Choice:\n0: Quit\n");
	printf("1: Find the month with the highest price\n");
	printf("2: Find the year with the highest average price\n");
}

oil *getOilData(oil *oilData) {
	FILE *oilfile = fopen("oil.txt", "r");
	char buffer[144] = "";
	oil *oilptr = oilData;
	int i = 0;

	for (int j = 0; j < 4; j++) {
		fgets(buffer, 144, oilfile);
	}
	while (i < yearcount) {
		fscanf(oilfile, "%d", &(oilptr + i)->year);
		for (int j = 0; j < 12; j++) {
			fscanf(oilfile, "%lf", &(oilptr + i)->price[j]);
		}
		(oilptr + i)->average = averagePrice((oilptr + i)->price); // Problem was here, forgot the + i
		i++;
	}
	fclose(oilfile);
	return oilData;
}

double averagePrice(double *prices) {
	return (prices[0] + prices[1] + prices[2] + prices[3] + prices[4] + prices[5] + prices[6] + prices[7] + prices[8] + prices[9] + prices[10] + prices[11]) / 12;
}

void highestPrice(oil *oilData) {
	oil *oilptr = oilData;
	oil *highestMonth = oilptr;
	int month = 0;
	for (int i = 0; i < yearcount; i++) {
		for (int j = 0; j < 12; j++) {
			if ((oilptr + i)->price[j] > highestMonth->price[month]) {
				highestMonth = (oilptr + i);
				month = j;
			}
		}
	}
	printf("\nHighest priced month was %lf in %s %d.\n\n", highestMonth->price[month], getMonth(month), highestMonth->year);
}

void highestAvgPrice(oil *oilData) {
	oil *oilptr = oilData;
	oil *highestAvgYear = oilptr;
	for (int i = 1; i < yearcount; i++) {
		if ((oilptr + i)->average > highestAvgYear->average) {
			highestAvgYear = (oilptr + i);
		}
	}
	printf("\nHighest annual average price was %lf in %d.\n\n", *(highestAvgYear->price), highestAvgYear->year);
}

int countYears() {
	FILE *oilfile = fopen("oil.txt", "r");
	char buffer[144] = "";
	int count = 0;
	while (!feof(oilfile)) {
		fgets(buffer, 144, oilfile);
		++count;
	}
	fclose(oilfile);
	return count - 6; // Account for lines at start and end which contain no useful info
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
	default: return "ERROR: Invalid month number";
	}
}
