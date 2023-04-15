/*
 * numeri perfetti
 * 
 * 
 */


#include <stdio.h>
#define LIMIT 9999999

int primo(int n);
int numero_perfetto(int n);

int main(int argc, char **argv)
{
	for(int i=1; i<LIMIT;++i) {
		if(numero_perfetto(i)) printf("%d\n", i);
	}
	
	
	
	return 0;
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
