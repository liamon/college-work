#include "stdafx.h"
#include <stdio.h>
#include <ctype.h>

int getLength(char string[]);
int isVowel(char c);
int countVowels (char string[]);

void toCapitals(char string[]);
void reverseString(char string[]);
void removeSpaces(char string[]);

int main() {
	char string[81];
	int numVowels, len;
	
	puts("Enter string:");
	gets_s(string, 80);
	
	len = getLength(string);
	printf("Length of String = %d\n", len);
	
	numVowels = countVowels(string);
	printf("Number of vowels = %d\n", numVowels);
	
	removeSpaces(string);
	printf("Without Spaces: %s\n", string);
	
	toCapitals(string);
	printf("In CAPITALS: %s\n", string);
	
	reverseString(string);
	printf("REVERSED: %s\n", string);
	
	return 0;
}

int getLength(char string[]) {
	int i = 0;
	while (string[i] != '\0') {
		i++;
	}
	return i;
}

int isVowel(char c) {
	int isVowel = 0;
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
		|| c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		isVowel = 1;
	}
	return isVowel;
}

int countVowels(char string[]) {
	int numVowels = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		if (isVowel(string[i]) == 1) {
			numVowels++;
		}
	}
	return numVowels;
}

void toCapitals(char string[]) {
	for (int i = 0; string[i] != '\0'; i++) {
		if (string[i] >= 'a' && string[i] <= 'z') {
			string[i] -= 32;
		}
	}
}

void reverseString(char string[]) {
	int len = getLength(string);
	char tmp[81];
	int j;
	
	for (j = 0; j < len; j++) {
		tmp[j] = string[len - j - 1];
	}
	tmp[j] = '\0';
	
	for (j = 0; j < len; j++) {
		string[j] = tmp[j];
	}
	string[j] = '\0';
}


void removeSpaces(char string[]) {
	int i = 0;
	int spaces = 0;
	while (string[i] != '\0') {
		if (string[i] == ' ') {
			spaces++;
		}
		i++;
	}
	
	for (int k = 0; string[k] != '\0'; k++){
		if (string[k] == ' '){
			for (; string[k] != '\0'; k++){
				string[k] = string[k + 1];
			}
			k = 0;
		}
	}
	/*
	This way to remove the spaces also works:

	for (; spaces > 0; spaces--){
		for (int k = 0; string[k] != '\0'; k++){
			if (string[k] == ' '){
				while (string[k] != '\0'){
					string[k] = string[k + 1];
					k++;
				}
			}
			// When I first did this there was a "spaces--;" here which
			// broke this method, but I did not realise it at the time
			// and instead switched over to the way I did it above.
		}
	}
	*/
}