/*
 * Gioco CRAPS
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, WON, LOST};

int rollDice(void);

int main(int argc, char **argv)
{
	srand(time(NULL)); // randomizza sulla base dell'ora corrente
	const int TIMES = 100000;
	int wins = 0;
	int loses = 0;
	for (int i = 0; i< TIMES; ++i) {
		int myPoint = 0;
		enum Status gameStatus = CONTINUE;
		int sum = rollDice(); //primo lancio dei dadi
		
		switch(sum) {
			//si vince al primo lancio
			case 7:
			case 11:
				gameStatus = WON;
				break;
			// si perde al primo lancio
			case 2:
			case 3:
			case 12:
				gameStatus = LOST;
				break;
			//ricorda il punteggio
			default:
				gameStatus = CONTINUE;
				myPoint = sum;
				printf("Point is %d\n", myPoint);
				break;
		}
		// il gioco continua
		while (CONTINUE == gameStatus) {
			sum = rollDice(); // lancio dei dadi
			
			if (sum == myPoint) {
				gameStatus = WON;
			} 
			else if (7 == sum) {
				gameStatus = LOST;
			}
		}
		
		// stampa il messaggio di vincita o perdita
		if (WON == gameStatus) {
			puts("Player wins");
			wins++;
		} else {
			puts("Player loses");
			loses++;
		}
	}
	
	printf("WINS: %d\nLOSES: %d\n",wins,loses);
	
}

int rollDice(void) {
	int die1 = 1 + (rand() % 6);
	int die2 = 1 + (rand() % 6);
	
	// stampa i risultati di questo lancio
	printf("Player rolled %d + %d = %d\n", die1, die2, die1+die2);
	return die1 + die2;
}
