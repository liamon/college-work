#include "stdafx.h"
#include <stdio.h>
#include <string.h>

int main() {
	char user[6] = "Admin", pass[13] = "password1234";
	char yourUser[20], yourPass[24];
	char firstN[20], initial[2], lastN[20];
	int charCount, userCheck, passCheck;
	
	printf("Enter your first name: ");
	scanf_s(" %s", firstN, 20);

	printf("Enter your middle initial: ");
	scanf_s(" %s", initial, 2);

	printf("Enter your last name: ");
	scanf_s(" %s", lastN, 20);
	printf("Your full name is: %s %s %s\n", firstN, initial, lastN);
	
	/*
	When I originally submitted this problem I accidentally left out the character count,
	which I have added in here for the sake of completeness.
	*/
	charCount = strlen(firstN) + 1 + strlen(initial) + 1 + strlen(lastN); // + 2 spaces
	printf("There are %d characters in your name\n\n", charCount);
	
	do {
		printf("Enter your username: ");
		scanf_s(" %s", yourUser, 20);
		printf("Enter your password: ");
		scanf_s(" %s", yourPass, 24);
		userCheck = strcmp(user, yourUser);
		passCheck = strcmp(pass, yourPass);

		if ((userCheck == 0) && (passCheck == 0))
		{
			puts("Login Correct");	
		}
		else
		{
			puts("Login Incorrect - Please try again:");
		}
	} while ((userCheck != 0) || (passCheck != 0));

	return 0;
}