#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

uint32_t  ricerca(FILE* f, char* str, char* look_str) {
	size_t i = 0, j = 0;
	char x; 
		for (;;) {
			x = fgetc(f);
			if (isprint(x) || x == '\n') {
				str = realloc(str, i + 1);
				str[i] = x == '\n' ? ' ' : x;
				++i;
			}
			else if (feof(f)) {
				str = realloc(str, i + 1);
				str[i] = '\0';
				break;
			}
	}
		uint32_t cont = 0;
		for (;;) {
			if (strlen(look_str) > i - j)
				return cont;
			++j;
			if (str[j] == look_str[0]) {
				for (size_t k = 0; k < strlen(look_str); ++k) {
					if (strlen(look_str) == k + 1)
						++cont;
					if (str[j] != look_str[k])
						break;
					 j++;
				}
			}
		}
}

// SAMPLE MAIN -- SAMPLE MAIN -- SAMPLE MAIN -- SAMPLE MAIN 
// SAMPLE MAIN -- SAMPLE MAIN -- SAMPLE MAIN -- SAMPLE MAIN

void main(void) {
	FILE* f = fopen("directory.txt", "r");
	if (ferror(f) || feof(f)) {
		fclose(f);
		return;
	}
	char* str = malloc(1); //FileIn
	char* lstr = "string_to_look_for"; //strstr
	ricerca(f, str, lstr);
	free(str);
	free(lstr);
	return;
}