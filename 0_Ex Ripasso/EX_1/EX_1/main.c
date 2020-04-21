
/*
Scrivere un programma che legga da linea di comando una stringa e due caratteri
diversi. Il programma deve contare le occorrenze dei caratteri nella stringa e
stampare su standard output quale carattere appare più volte.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// PONENDO
// argv[0] -> prog. name
// argv[1] -> stringa
// argv[2] -> 1 char
// argv[3] -> 2 char


void main(int argc, char* argv[]) {
	char* str = argv[1];
	char* x = tolower(argv[2]);
	char* y = tolower(argv[3]);
	char max;
	unsigned short contx = 0, conty = 0;
	for (size_t i = 0; i < strlen(str); ++i) {
		if (tolower(str[i]) == *x)
			++contx;
		if (tolower(str[i]) == *y)
			++conty;
	}
	max = contx > conty ? *x : *y;
	printf("%c", max);
	return;
}