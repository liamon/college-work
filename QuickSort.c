#include "stdafx.h"
#include <stdio.h>
#include <time.h>

#define SIZE 100000

void quickSort(int num[], int start, int end);

int main() {
	FILE *intNos, *intNosSorted;
	int i = 0;
	int numbers[SIZE];
	clock_t timeTaken;
	
	fopen_s(&intNos, "C:/Users/Liam/Downloads/intNos.txt", "r");
	if (intNos == NULL) { // Test if the file was able to open properly
		puts("Error opening file.");
		return 1;
	}
	while (i < SIZE) {
		fscanf_s(intNos, "%d", &numbers[i++]);
	}
	fclose(intNos); // No longer need intNos.txt so I can close it
	
	timeTaken = clock(); // mergeSort is recursive so I have to measure time taken outside the function
	quickSort(numbers, 0, SIZE - 1);
	timeTaken = clock() - timeTaken;
	
	i = 0;
	fopen_s(&intNosSorted, "C:/Users/Liam/Documents/intNosSorted.txt", "w");
	while (i < SIZE) {
		fprintf(intNosSorted, "%d\n", numbers[i++])3 // The number is printed to the file THEN incremented by 1
	}
	fclose(intNosSorted); // No longer need intNosSorted.txt so I can close it
	
	printf("Time taken to sort by QUICK SORT: %lf seconds.\n\n", double(timeTaken)/CLOCKS_PER_SEC);
	return 0;
}

void quickSort(int num[], int start, int end)
	int i, j, temp, pivot;
	i = start;
	j = end;
	pivot = num[start];
	
	if (end - start < 1) {
		return; // When end & start are the same position, return to top function to avoid infinite recursion
	} else {
		while (j > i) {
			while (num[i] <= pivot && i <= j && i <= end) {
				i++;
			}
			while (num[j] > pivot && j >= i && j >= start) {
				j-;
			}
			if (j > i) { // Swap around num[i] and num[j] so they are on right sides of pivot
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}
	// Move num[j] into the correct position...
	temp = num[start];
	num[start] = num[j];
	num[j] = temp;
	
	// ...so j can be ignored in the next 2 function calls
	quickSort(num, start, j - 1);
	quickSort(num, j + 1, end);
}
