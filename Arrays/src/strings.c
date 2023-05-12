/*
 * strings.c
 *
 *  Created on: 27 apr 2023
 *      Author: enric
 */
#define MAX_STRING_LENGTH 21
#include <stdio.h>

void sec_input_string() {
	char string[MAX_STRING_LENGTH];

	for (int i = 0; i < 3; ++i) {
		printf("%s", "Insert a string no longer than 20 char: ");
		scanf("%20s", string);
		printf("Readed: %s\n", string);
	}
}
