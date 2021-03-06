// Functional Forecasts

// Chandler Noe - 2020

#include "header.h"

int main(void) {

	struct user primary;
	char choice[2];
	int quit = 1;

	printf("---------------- Functional Forecasts ----------------\n\n");
	printf("----------------- Chandler Noe 2020 ------------------\n\n");
	printf("Welcome! Please choose your preferences. These values can be changed later!\n\n");
	updatePreferences(&primary.key,&primary.units,&primary.lang);

	//Main loop
	do {

		//Debugging purposes only
		//printf("\n");
		//printf("Units: %s\n\n", primary.units);
		//printf("Lang: %s\n\n", primary.lang);
		//printf("Key: %s\n\n", primary.key);

		printf("Select an option.\n");
		printf("1: Forecast\n2: Update Preferences\n3: Help\n4: Quit\n\n");
		getInput("Selection: ", choice, sizeof(choice));
		printf("\n");
		switch(atoi(choice)) {

			case 1:
				printf("Forecast\n\n");
				break;
			case 2:
				updatePreferences(&primary.key,&primary.units,&primary.lang);
				break;
			case 3:
				printHelp();
				break;
			case 4:
				printf("Quitting...\n\n");
				quit = 0;
				break;
			default:
				printf("Invalid selection!!!\n\n");
				break;
	
		}

	} while (quit);

	//Free (make function)
	free(primary.units);
	free(primary.lang);
	free(primary.key);

	return 0;

}

void updatePreferences(char **userKey,char **userUnits,char **userLang) {

	getKey(&userKey);
	getUnits(&userUnits);
	getLang(&userLang);

	return;

}

void getKey(char ***origKey) {

	//Unhardcode this, max api key length?
	char choice[33];
	int valid = 1;
	int ret;

	ret = getInput("Please enter your OpenWeatherMap API key: ", choice, sizeof(choice));
	if (ret == NO_INPUT || ret == TOO_LONG) {
		printf("\nInvalid key!!! getInput!\n\n");
		getKey(origKey);
	}
	//Poll API to see if this is a valid key
	if (valid) {
		
		**origKey = malloc(strlen(choice)+1);
		strcpy(**origKey, choice);
		return;

	}
	else {

		printf("\nInvalid key!!!\n\n");
		getKey(origKey);

	}

}

void getLang(char ***origLang) {

	int i, ret;
	int valid = 1;
	char choice[3];
	//Read from file? Unhardcode height?
	char *languages[46][2] = {

		{"Afrikaans","af"},
		{"Albanian","al"},
		{"Arabic","ar"},
		{"Azerbaijani","az"},
		{"Bulgarian","bg"},
		{"Catalan","ca"},
		{"Czech","cz"},
		{"Danish","da"},
		{"German","de"},
		{"Greek","el"},
		{"English","en"},
		{"Basque","eu"},
		{"Persian (Farsi)","fa"},
		{"Finnish","fi"},
		{"French","fr"},
		{"Galician","gl"},
		{"Hebrew","he"},
		{"Hindi","hi"},
		{"Croatian","hr"},
		{"Hungarian","hu"},
		{"Indonesian","id"},
		{"Italian","it"},
		{"Japanese","ja"},
		{"Korean","kr"},
		{"Latvian","la"},
		{"Lithuanian","lt"},
		{"Macedonian","mk"},
		{"Norwegian","no"},
		{"Dutch","nl"},
		{"Polish","pl"},
		{"Portuguese","pt"},
		{"Portugues Brasil","pt_br"},
		{"Romanian","ro"},
		{"Russian","ru"},
		{"Swedish","sv"}, /*se*/
		{"Slovak","sk"},
		{"Slovenian","sl"},
		{"Spanish","sp"}, /*es*/
		{"Serbian","sr"},
		{"Thai","th"},
		{"Turkish","tr"},
		{"Ukrainian","ua"}, /*uk*/
		{"Vietnamese","vi"},
		{"Chinese Simplified","zh_cn"},
		{"Chinese Traditional","zh_tw"},
		{"Zulu","zu"}

	};

	while (valid) {

		printf("\nPlease select an option for your preferred language: \n");
		for (i=0;i<46;i++) {

			if (i % 2 == 0 && i != 0)
				printf("\n");
				printf("%i: %-24s", i+1, languages[i][0]);
		
		}
		printf("\n\n");
		ret = getInput("Selection: ", choice, sizeof(choice));
		printf("\n");
		//printf("\nChoice: %s\n", choice);
		if (ret == NO_INPUT || ret == TOO_LONG || atoi(choice) < 1 || atoi(choice) > 46)
			printf("\nInvalid selection!!!\n\n");
		else {

			**origLang = malloc(strlen(languages[atoi(choice)-1][1])+1);
			strcpy(**origLang, languages[atoi(choice)-1][1]);
			valid = 0;
			return;

		}

	}

}

void getUnits(char ***origUnits) {

	char choice[2];
	int ret;
	int valid = 1;

	while (valid) {

		printf("\nPlease select an option for your preferred measurement: \n");
		printf("1: Standard\n2: Metric\n3: Imperial\n\n");
		ret = getInput("Selection: ", choice, sizeof(choice));
		if (ret == NO_INPUT || ret == TOO_LONG)
			valid = 1;
		switch (atoi(choice)) {

			case 1:
				//Standard
				**origUnits = malloc(strlen("standard")+1);
				strcpy(**origUnits, "standard");
				valid = 0;
				return;
			case 2:
				//Metric
				**origUnits = malloc(strlen("metric")+1);
				strcpy(**origUnits, "metric");
				valid = 0;
				return;
			case 3:
				//Imperial
				**origUnits = malloc(strlen("imperial")+1);
				strcpy(**origUnits, "imperial");
				valid = 0;
				return;
			default:
				break;

		}

		printf("\nInvalid selection!!!\n\n");
	
	}

}

//This should not be called with a buffer < 2 !!!
int getInput (char *prompt,char *buffer, size_t bufferSize) {
	
	size_t length;
	int count, ch;

	if (bufferSize < 2)
		return SMALL_BUFFER;

	if (prompt != NULL) {
		printf("%s",prompt);
		fflush(stdout);
	}

	if (fgets(buffer, bufferSize, stdin) == NULL)
		return NO_INPUT;
	
	length = strlen(buffer);
	if (length < 1)
		return NO_INPUT;

	if (buffer[length-1] != '\n') {
		count = 0;
		while (((ch = getchar()) != '\n') && (ch != EOF))
			count = 1;
		return (count == 1) ? TOO_LONG : VALID;
	}

	buffer[length - 1] = '\0';
	return VALID;

}

void printHelp(void) {

	printf("Lorem ipsum dolor sit amet\n\n");
	return;

}
