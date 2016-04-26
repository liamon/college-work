#include "stdafx.h"
#include <stdio.h>
#include <time.h> 

#define SIZE 100000

clock_t timeTaken; // This variable must be global so both main and countSort can access it

void countSort(int num[], int start, int end); 

int main() {
	FILE *intNos, *intNosSorted;
	int i = 0;
	int numbers[SIZE];

	fopen_s(&intNos, "C:/Users/Liam/Downloads/intNos.txt", "r");
	if (intNos == NULL) { // Test if the file was able to open properly
		puts("Error opening file.");
		return 1;
	}
	while (i < SIZE) {
		fscanf_s(intNos, "%d", &numbers[i++]);
	}
	fclose(intNos); // No longer need intNos.txt so I can close it

	countSort(numbers, 0, SIZE - 1); 
	
	i = 0;
	fopen_s(&intNosSorted, "C:/Users/Liam/Documents/intNosSorted.txt", "w");
	while (i < SIZE) {
		fprintf(intNosSorted, "%d\n", numbers[i++]); // The number is printed to the file THEN incremented by 1
	}
	fclose(intNosSorted); // No longer need intNosSorted.txt so I can close it 

	printf("Time taken to sort by COUNT SORT: %lf seconds.\n\n", double(timeTaken)/CLOCKS_PER_SEC);
	return 0;
}

void countSort(int num[], int start, int end) {
	timeTaken = clock(); 

	int i, val, count;
	int temp[SIZE];
	int freq[1001] = { 0 }; // Initializes every member of freq array to 0 
	
	for (i = 0; i < SIZE; i++) {
		freq[num[i]]++;
	}
	for (i = 1; i <= 1000; i++) {
		freq[i] += freq[i - 1]; // Gets the count of every number <= i
	}
	for (i = 0; i < SIZE; i++) {
		val = num[i];
		count = freq[val];
		temp[count - 1] = val; // If there was no "- 1" then temp[0] would be empty
		freq[val]--;
	}
	for (i = 0; i < SIZE; i++) {
		num[i] = temp[i];
	}

	timeTaken = clock() - timeTaken;
}
