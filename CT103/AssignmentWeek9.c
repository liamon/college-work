#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

#define LEN 20

void populateArray(int numbers[], int length);
void populateArrayRange(int numbers[], int length, int minNum, int maxNum);
double getAverage(int numbers[], int length);
int getMax(int numbers[], int length);
int getMin(int numbers[], int length);
void printArray(int numbers[], int length);

int main() {
	int intArray[LEN];
	double average;
	int max, min;
	
	srand(time(0));
	populateArray(intArray, LEN);
	populateArrayRange(intArray, LEN, 11, 23);
	
	average = getAverage(intArray, LEN);
	max = getMax(intArray, LEN);
	min = getMin(intArray, LEN);
	
	puts("Array of Integers:");
	printArray(intArray, LEN);
	printf("Average = %.2lf, Min = %d, Max = %d\n", average, min, max);
	
	return 0;
}

void populateArray(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		numbers[i] = rand();
	}
}

void populateArrayRange(int numbers[], int length, int minNum, int maxNum) {
	for (int i = 0; i < length; i++) {
		numbers[i] = rand() % (maxNum - minNum + 1) + minNum;
	}
}

double getAverage(int numbers[], int length) {
	int total = 0;
	for (int i = 0; i < length; i++) {
		total = total + numbers[i];
	}
	double average = total / (double)length;
	return average;
}

int getMax(int numbers[], int length) {
	int max = numbers[0];
	for (int i = 1; i < length; i++) {
		if (max < numbers[i]) {
			max = numbers[i];
		}
	}
	return max;
}

int getMin(int numbers[], int length) {
	int min = numbers[0];
	for (int i = 1; i < length; i++) {
		if (min > numbers[i]) {
			min = numbers[i];
		}
	}
	return min;
}

void printArray(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		printf("%-10d", numbers[i]);
		if ((i + 1) % 5 == 0) {
			printf("\n\n");
		}
	}
}