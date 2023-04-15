/*
 * calcolo del valore di pigreco
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
	
	const int TERMS = 500000;
	double pi = 0;
	int j = 5;
	do {
		pi = 0;
		int den = 1;
		for(int i = 1; i < j; ++i) {
			if (i%2 == 0) {
				pi -= (double) 4 / den;
			} else {
				pi += (double) 4 / den;
			}
			
			den += 2;
		}
		printf("Result with %d terms: %lf\r",j, pi);
		++j;
	}while(j<= TERMS && fabs(pi - 3.14159) > 0.000001);
	
	
	return 0;
}

