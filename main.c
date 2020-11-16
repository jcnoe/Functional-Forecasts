// Functional Forecasts

// Chandler Noe - 2020

// 6deaf3408385dc5d36ccc6543b8cd84e

#include "header.h"

int main(void) {

	struct user primary;

	printf("---------------- Functional Forecasts ----------------\n\n");
	printf("----------------- Chandler Noe 2020 ------------------\n\n");
	printf("Welcome! Please choose your preferences. These values can be changed later!\n\n");
	updatePreferences(&primary.key,&primary.units,&primary.lang);
	
	printf("Units: %s\n\n", primary.units);
	printf("Lang: %s\n\n", primary.lang);
	printf("Key: %s\n\n", primary.key);
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
	printf("Please enter your OpenWeatherMap API key: ");
	fgets(choice, 33, stdin);
	fflush(stdin);
	printf("\n");
	//Poll API to see if this is a valid key
	if (valid) {
		
		**origKey = malloc(strlen(choice)+1);
		strcpy(**origKey, choice);
		return;

	}
	else {

		printf("Invalid key!!!\n\n");
		getKey(origKey);

	}

}

void getLang(char ***origLang) {

	int choice,i;
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

	printf("Please select an option for your preferred language: \n");
	for (i=0;i<46;i++) {

		printf("%i: %s\n", i+1, languages[i][0]);

	}
	printf("Selection: ");
	scanf("%i", &choice);
	printf("\n");
	if (choice < 1 || choice > 46) {
		
		printf("Invalid selection!!!\n\n");
		getLang(origLang);

	}
	else {

		**origLang = malloc(strlen(languages[choice-1][1])+1);
		strcpy(**origLang, languages[choice-1][1]);
		return;

	}

}

void getUnits(char ***origUnits) {

	char choice[1];

	printf("Please select an option for your preferred measurement: \n");
	printf("1: Standard\n2: Metric\n3: Imperial\n\n");
	printf("Selection: ");
	//This needs to be sorted out
	fgets(choice, 2, stdin);
	printf("\n");
	switch (atoi(choice)) {

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
