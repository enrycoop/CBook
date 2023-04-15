/*
 * Programma che stampa un rombo
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	const int SIZE = 100;
	for (int i = 1; i < SIZE; i+=2) {
		for (int k = 0; k < (SIZE-i)/2; k++) {
			printf("%s", " ");
		}
		for (int k = 0; k < i; k++) {
			printf("%s", "*");
		}
		puts("");
	}
	for (int i = SIZE-3; i > 0 ; i-=2) {
		for (int k = 0; k < (SIZE-i)/2; k++) {
			printf("%s", " ");
		}
		for (int k = 0; k < i; k++) {
			printf("%s", "*");
		}
		puts("");
	}
	
	return 0;
}

