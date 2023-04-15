/*
 * c5_3.c 
 * 
 */


#include <stdio.h>

unsigned long long int factorial(unsigned long long int number);
unsigned long long int fibonacci(unsigned long long int number);

int main(int argc, char **argv)
{
	
	for(unsigned long long int i = 0; i < 20; ++i) {
		printf("%llu! = %llu!\n",i,factorial(i));
	}
	
	for(unsigned long long int i = 0; i < 30; ++i) {
		printf("%llu! = %llu!\n",i,fibonacci(i));
	}
	
	return 0;
}

unsigned long long int factorial(unsigned long long int number) {
	if (number <= 1) {
		return 1;
	} else {
		return (number * factorial(number -1 ));
	}
}

unsigned long long int fibonacci(unsigned long long int number) {
	if (number == 1 || number == 0) {
		return number;
	} else {
		return fibonacci(number - 1) + fibonacci(number - 2);
	}
}
