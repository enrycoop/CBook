/*
 * numeri perfetti
 * 
 * 
 */


#include <stdio.h>
#define LIMIT 10

int primo(int n);
int numero_perfetto(int n);
int power(int base, int exp);
unsigned long long int fibonacci(unsigned long long int term);

int main(int argc, char **argv)
{
	for(int i=0; i<LIMIT;++i) {
		printf("%d..", fibonacci(i));
	}
	
	return 0;
}


unsigned long long int fibonacci(unsigned long long int term) {
	if (term == 1 || term == 0) return term;
	
	unsigned long long int pre = 0;
	unsigned long long int actual = 1;
	for (unsigned long long int i = 1;i <= term; ++i) {
		unsigned long long int temp = actual;
		actual += pre;
		pre = temp;
	}
	return actual;
}
int primo(int n) {
	int div = 0;
	for(int i=2; i<n; ++i){
		if (n%i==0) ++div;
	}
	return div==0;
}

int numero_perfetto(int n) {
	int sum = 0;
	for (int i = 1; i<n; ++i) {
		if (n%i==0) sum += i;
	}
	return sum==n;
}

int power(int base, int exp) {
	if (exp == 1) {
		return base;
	}else{
		return base * power(base, exp-1);
	}
}
