#include "stdafx.h"
#include <stdio.h>
#include <time.h>

#define SIZE 100000

void mergeSort(int num[], int start, int end);
void merge(int num[], int start, int mid, int end);

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
	mergeSort(numbers, 0, SIZE - 1);
	timeTaken = clock() - timeTaken;
	
	i = 0;
	fopen_s(&intNosSorted, "C:/Users/Liam/Documents/intNosSorted.txt", "w");
	while (i < SIZE) {
		fprintf(intNosSorted, "%d\n", numbers[i++])3 // The number is printed to the file THEN incremented by 1
	}
	fclose(intNosSorted); // No longer need intNosSorted.txt so I can close it
	
	printf("Time taken to sort by MERGE SORT: %lf seconds.\n\n", double(timeTaken)/CLOCKS_PER_SEC);
	return 0;
}

void mergeSort(int num[], int start, int end)
	int middle;
	if (start < end) { // As long as start and end are 2 different postions in array, this will be true
		middle = (start + end) / 2;
		mergeSort(num, start, middle);
		mergeSort(num, middle + 1, end);
		merge(num, start, middle, end);
	}
}

void merge(int num[], int start, int mid, int end)
	int temp[SIZE];
	int i, j, k;
	i = k = start;
	j = mid + 1; // j is the start of the second half of the array
	
	while (i <= mid && j <= end) { // Keep going through array until one half is sorted
		if (num[i] < num[j]) {
			temp[k] = num[i];
			i++;
			k++;
		} else {
			temp[k] = num[j];
			j++;
			k++;
		}
	}
	if (j == end + 1) { // Check which condition in last while loop became false so I can go through the other half
		while (i <= mid)
			temp[k] = num[i];
			i++;
			k++;
		}
	} else {
		while (j <= end) {
			temp[k] = num[j];
			j++;
			k++;
		}
	}
	for (k = start; k <= end; k++) {
		num[k] = temp[k];
	}
}
