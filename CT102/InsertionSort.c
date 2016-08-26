#include "stdafx.h"
#include <stdio.h>

#define SIZE 100

int main(void) {
	FILE *realNos, *realNosSorted;
	int i = 0, j;
	double realNumbers[SIZE];
	double current;
	double total = 0.0;

	fopen_s(&realNos, "C:/Users/Liam/Downloads/realNos.txt", "r");
	if (realNos == NULL) { // Test if the file was able to open properly
		puts("Error opening file.");
		return 1;
	}
	while (i < SIZE) {
		fscanf_s(realNos, "%lf", &realNumbers[i++]);
	}
	fclose(realNos); // No longer need realNos.txt so I can close it
	
	i = 1;
	while (i < SIZE) {
		current = realNumbers[i];
		j = i - 1;
		while (current < realNumbers[j]) {
			realNumbers[j + 1] = realNumbers[j];
			j-;
		}
		realNumbers[j + 1] = current;
		i++;
	}
	i = 0;
	fopen_s(&realNosSorted, "C:/Users/Liam/Documents/realNosSorted.txt", "w");

	while (i < SIZE) {
		fprintf(realNosSorted, "%lf\n", realNumbers[i++]); // The number is printed to the file THEN incremented by 1
	}
	i = 0;
	fclose(realNosSorted); // No longer need realNosSorted.txt so I can close it

	while (i < SIZE) {
		total += realNumbers[i++];
	}
	printf("Smallest = %lf\nLargest = %lf\nAverage = %lf\n", realNumbers[0], realNumbers[99], total / 100);
	return 0;
}
