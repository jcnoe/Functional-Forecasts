#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80
#define MAXSIZE 256

#define VALID 0
#define NO_INPUT 1
#define TOO_LONG 2
#define SMALL_BUFFER 3

void updatePreferences(char **,char **,char **);

void getKey(char ***);

void getLang(char ***);

void getUnits(char ***);

int getInput(char *, char *, size_t);

void printHelp(void);

struct user {

	char *units;
	char *lang;
	char *key;

};

#endif
