/*
 * c5_2.c
 * 
 */


#include <stdio.h>

void useLocal(void);
void useStaticLocal(void);
void useGlobal(void);


int x = 1;

int main(int argc, char **argv)
{
	printf("%d\n", x);
	int x = 5;
	printf("%d\n", x);
	
	
	{
		printf("%d\n", x);
		int x = 7;
		printf("%d\n", x);
	}
	printf("%d\n", x);
	
	useLocal();
	useStaticLocal();
	useGlobal();
	useLocal();
	useStaticLocal();
	useGlobal();
	
	return 0;
}

void useLocal(void) {
	int x = 25;
	printf("useLocal | %d\n", x);
	++x;
	printf("useLocal | %d\n", x);
}

void useStaticLocal(void){
	static int x = 50;
	printf("useStaticLocal | %d\n", x);
	++x;
	printf("useStaticLocal | %d\n", x);
}

void useGlobal(void){
	printf("useGlobal | %d\n", x);
	x *= 10;
	printf("useGlobal | %d\n", x);
}
