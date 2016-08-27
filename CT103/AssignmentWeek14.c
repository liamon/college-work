#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 101

int main() {
	FILE *accounts;
	int id;
	double balance;
	int ids[SIZE];
	double balances[SIZE];
	
	fopen_s(&accounts, "accounts.txt", "w");
	srand(time(NULL));
	for (id = 0; id < SIZE; id++) {
		balance = (double)rand() - 10000;
		fprintf(accounts, "%04d\t%8.2lf\n", id, balance);
	}
	fclose(accounts);
	
	fopen_s(&accounts, "accounts.txt", "r");
	for (int i = 0; i < SIZE; i++) {
		fscanf_s(accounts, "%d%lf", &ids[i], &balances[i]);
	}
	for (int i = 0; i < SIZE; i++) {
		printf("%04d\t%8.2lf\n", ids[i], balances[i]);
	}
	fclose(accounts);
	
	puts("\nACCOUNTS WITH A NEGATIVE BALANCE\n************************************");
	for (int i = 0; i < SIZE; i++) {
		if (balances[i] < 0.0) {
			printf("%04d\t%8.2lf\n", ids[i], balances[i]);
		}
	}
	return 0;
}