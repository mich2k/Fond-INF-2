#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 10000

void min_to_maiusc(char* str, size_t n) {
	char* p;
	for (size_t i = 0;i < n; ++i) {
		p = (str + i);
		if (i != 0 && *p == '\0') break;
		if (isalpha(*p)) {
			if (islower(*p))
				*p = toupper(*p);
		}
	}
}

void main ( void ){
	char* s = malloc(MAX);
	fprintf(stdout, "Ins. str: ");
	fscanf(stdin, "%s", s);
	s = realloc(s, strlen(s) + 1);
	min_to_maiusc(s, strlen(s));
	for (size_t i = 0; i < strlen(s); i++)
		fprintf(stdout, "%c", *(s + i));
	free(s);
	return;
}