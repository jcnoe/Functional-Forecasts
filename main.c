// Functional Forecasts

// Chandler Noe - 2020

// 6deaf3408385dc5d36ccc6543b8cd84e

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user updatePreferences(struct user);

struct user {

	char units[9];
	char lang[2];

};

int main(void) {

	struct user primary;

	printf("---------------- Functional Forecasts ----------------\n\n");
	printf("----------------- Chandler Noe 2020 ------------------\n\n");
	printf("Welcome! Please choose your preferences. These values can be changed later!\n\n");
	primary = updatePreferences(primary);



	return 0;

}

struct user updatePreferences(struct user old) {

	struct user new = old;
	char measurement[9];
	char language[32];

	printf("What are your preferred units of measurement? (Standard, Metric, Imperial): ");
	scanf("%s", measurement);
	printf("\n");
	//Add error checking and decapitalization
	strcpy(new.units, measurement);
	printf("Please select a language: ");
	//Add loop to print available languages
	scanf("%s", language);
	printf("\n");
	//Add error checking and conversion to two digit language code
	//new.lang = language;

	return new;

}
