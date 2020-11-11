// Functional Forecasts

// Chandler Noe - 2020

// 6deaf3408385dc5d36ccc6543b8cd84e

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updatePreferences(char **,char **);
void getLang(char ***);
void getUnits(char ***);

struct user {

	char *units;
	char *lang;

};

int main(void) {

	struct user primary;

	printf("---------------- Functional Forecasts ----------------\n\n");
	printf("----------------- Chandler Noe 2020 ------------------\n\n");
	printf("Welcome! Please choose your preferences. These values can be changed later!\n\n");
	updatePreferences(&primary.units,&primary.lang);

	printf("Units: %s\n\n", primary.units);
	//printf("Lang: %s\n\n", primary.lang);

	free(primary.units);
	//free(primary.lang);

	return 0;

}

void updatePreferences(char **userUnits,char **userLang) {

	getUnits(&userUnits);
	getLang(&userLang);

	return;

}

void getLang(char ***origLang) {

	int choice;

	printf("Please select an option for your preferred language: \n");

	printf("Selection: ");
	scanf("%i", &choice);
	printf("\n");


	return;

	getLang(origLang);

}

void getUnits(char ***origUnits) {

	int choice;

	printf("Please select an option for your preferred measurement: \n");
	printf("1: Standard\n2: Metric\n3: Imperial\n\n");
	printf("Selection: ");
	scanf("%i", &choice);
	printf("\n");
	switch (choice) {

		case 1:
			//Standard
			**origUnits = malloc(strlen("standard")+1);
			strcpy(**origUnits, "standard");
			return;
		case 2:
			//Metric
			**origUnits = malloc(strlen("metric")+1);
			strcpy(**origUnits, "metric");
			return;
		case 3:
			//Imperial
			**origUnits = malloc(strlen("imperial")+1);
			strcpy(**origUnits, "imperial");
			return;
		default:
			printf("Invalid selection!!!\n\n");
			break;

	}

	getUnits(origUnits);

}
