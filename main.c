// Functional Forecasts

// Chandler Noe - 2020

// 6deaf3408385dc5d36ccc6543b8cd84e

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updatePreferences(char **);
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
	printf("main %p\n\n",primary.units);
	updatePreferences(&primary.units);

	printf("Units: %s", primary.units);

	//free(primary.units);
	
	return 0;

}

void updatePreferences(char **userUnits) {

	//char language[32];

	printf("update %p\n\n",userUnits);
	getUnits(&userUnits);
	//printf("Please select a language: ");
	//Add loop to print available languages
	//scanf("%s", language);
	//printf("\n");
	//Add error checking and conversion to two digit language code
	//new.lang = language;
	//getLanguage();

	return;

}

void getUnits(char ***orig) {

	int choice;

	printf("getUnits %p\n\n",orig);

	printf("Please select an option for your preferred measurement: \n");
	//Loop thru options
	printf("Preference: ");
	scanf("%i", &choice);
	switch (choice) {

		case 1:
			//Standard
			**orig = malloc(strlen("standard")+1);
			strcpy(**orig, "standard");
			return;
		case 2:
			//Metric
			**orig = malloc(strlen("metric")+1);
			strcpy(**orig, "metric");
			return;
		case 3:
			//Imperial
			**orig = malloc(strlen("imperial")+1);
			strcpy(**orig, "imperial");
			return;
		default:
			printf("Invalid choice!\n");
			break;

	}

	getUnits(orig);

}
