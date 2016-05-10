#include "stdafx.h"
#include <stdio.h>
#include <time.h>

#define SIZE 100000

void insertionSort(int num[]);

clock_t timeTaken; // This variable must be global so both main and insertionSort can access it

int main(void)
	FILE *intNos, *intNosSorted;
	int i = 0;
	int numbers[SIZE];
	
	fopen_s(&intNos, "C:/Users/Liam/Downloads/intNos.txt", "r");
	if (intNos == NULL) { // Test if the file was able to open properly
		puts("Error opening file.");
		return 1;
	}
	while (i < SIZE) {
		fscanf_s(intNos, ”%d”, &numbers[i++]);
	}
	fclose(intNos); // No longer need intNos.txt so I can close it
	
	insertionSort(numbers);
	
	i = 0;
	fopen_s(&intNosSorted, "C:/Users/Liam/Documents/intNosSorted.txt", "w");
	while (i < SIZE) {
		fprintf(intNosSorted, "%d\n", numbers[i++]); // The number is printed to the file THEN incremented by 1
	}
	fclose(intNosSorted); // No longer need intNosSorted.txt so I can close it

	printf("Time taken to sort by INSERTION SORT: %lf seconds.\n\n", double(timeTaken)/CLOCKS_PER_SEC);
	return 0;
}

void insertionSort(int num[])
	timeTaken = clock();
	int i = 1; // Doesn't try to check if current is lower than num[-1] in the second while loop
	int current, j;
	
	while (i < SIZE) {
		current = num[i];
		j = i - 1;
		while (current < num[j]) {
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = current;
		i++;
	}
	timeTaken = clock() - timeTaken;
}
