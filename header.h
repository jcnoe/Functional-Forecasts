#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void updatePreferences(char **,char **);

void getLang(char ***);

void getUnits(char ***);

struct user {

	char *units;
	char *lang;

};

#endif
