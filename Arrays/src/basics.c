/*
 * basics.c
 *
 *  Created on: 22 apr 2023
 *      Author: sergio
 */

#include "basics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define ROLLS 100

void init_array() {
	int n[5];

	/*
	 * Alternativamente si può usare int n[5] = {0}; per inizializzare
	 * tutti gli elementi a 0, poichè inizializza solo il primo a 0 ma
	 * non trovando gli altri elementi nella inizializzazione a lista
	 * i restanti li inizializza in automatico a zero.
	 * Da notare che va definita la dimensione tra le [] altrimenti non
	 * sa di quanto deve inizializzare l'array.
	 */
	for (size_t i = 0; i < 5; ++i) {
		n[i] = 0;
	}

	printf("%s%8s\n", "Element", "Value");

	for (size_t i = 0; i < 5; ++i) {
		printf("%7zu%8d\n", i, n[i]);
	}
}

void init_list_array() {
	int n[] = {32, 27, 64, 18, 95};

	printf("%s%8s\n", "Element", "Value");

	for (size_t i = 0; i < 5; ++i) {
		printf("%7zu%8d\n", i, n[i]);
	}
}


void textual_bar_graph_array() {
	int n[SIZE] = {19, 3, 15, 7, 11};

	printf("%s%13s%17s\n", "Element", "Value", "Bar Chart");

	for (size_t i = 0; i < SIZE; ++i) {
		printf("%7zu%13d%8s", i, n[i] , "");

		for (size_t j = 0; j < n[i]; ++j) {
			printf("%c", '*');
		}
		puts("");
	}
}

void dice_textual_bar_graph_array() {
	int frequency[7] = {0};

	srand(time(NULL));

	for (int roll = 0; roll < ROLLS; ++roll) {
		size_t face = 1 + rand() % 6;
		++frequency[face];
	}

	printf("%s%13s%17s\n", "Face", "Frequency", "Bar Chart");

	for (size_t i = 1; i < 7; ++i) {
		printf("%7zu%13d%8s", i, frequency[i] , "");

		for (size_t j = 0; j < frequency[i]; ++j) {
			printf("%c", '*');
		}
		puts("");
	}
}
