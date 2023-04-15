/*
 * Numeri romani da 1 a 100
 * 
 * 
 */


#include <stdio.h>

int main(int argc, char **argv)
{
	
	for(int n = 1; n<=100; ++n) {
		int III = (n/100)%10;
		int II = n/10%10;
		int I = (n - n/10*10 -n/100*100)%10;
		printf("%d %d %d -> ", III, II, I);
		
		switch(III) {
			case 0:
			break;
			case 1:
			printf("%s","C");
		}
		
		switch(II){
			case 1:
				printf("%s", "X");
				break;
			case 2:
				printf("%s", "XX");
				break;
			case 3:
				printf("%s", "XXX");
				break;
			case 4:
				printf("%s", "XL");
				break;
			case 5:
				printf("%s", "L");
				break;
			case 6:
				printf("%s", "LX");
				break;
			case 7:
				printf("%s", "LXX");
				break;
			case 8:
				printf("%s", "LXXX");
				break;
			case 9:
				printf("%s", "XC");
				break;
			default:
				printf("%s", "");
				break;
		}
		
		switch(I){
			case 1:
				puts("I");
				break;
			case 2:
				puts("II");
				break;
			case 3:
				puts("III");
				break;
			case 4:
				puts("IV");
				break;
			case 5:
				puts("V");
				break;
			case 6:
				puts("VI");
				break;
			case 7:
				puts("VII");
				break;
			case 8:
				puts("VIII");
				break;
			case 9:
				puts("IX");
				break;
			default:
				puts("");
				break;
		}
	}
	
	
	return 0;
}

