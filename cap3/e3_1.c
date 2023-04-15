/*
 * Consumo di carburante
 * Programma che registra il consumo di carburante
 * I guidatori sono interessati al consumo effettuato dalle loro automobili.
 * Un guidatore ha tenuto traccia dei vari pieni di carburante, registrando
 * le miglia percorse e i litri consumati per ogni pieno. Realizzare un 
 * programma che utilizzi scanf per richiedere l'inserimento delle miglia
 * percorse e dei litri consumati per ogni pieno. Il programma deve 
 * calcolare e stampare le miglia per litro percorse per ogni pieno.
 * Dopo aver processato tutte le informazioni di input, il programma 
 * deve calcolare e stampare le miglia complessive per litro percorse 
 * per tutti i pieni.
 * 
 * Top-down
 * 
 * 1st
 * 
 * inizializzazione delle variabili
 * richiesta dati in input
 * calcolo del dispendio per pieno
 * calcolo totale
 * esposizione risultati
 * 
 */


#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
	
	// inizializzazione delle variabili
	int kilometers = 0;
	double liters = 0;
	int tot_kilometers = 0;
	double tot_liters = 0;
	double consume = 0;
	
	//richiesta dei dati in input
	printf("%s", "Enter km driven (-1 to end): ");
	do{
		scanf("%d", &kilometers);
		if(kilometers <= INT_MIN || kilometers > INT_MAX){
			printf("Invalid input, must be in [%d, %d] interval.\n",
			 INT_MIN, INT_MAX);
		}
	}while (kilometers < INT_MIN || kilometers > INT_MAX);
	tot_kilometers+=kilometers;
	
	printf("%s", "Enter liters used: ");
	do{
		scanf("%lf", &liters);
		if(liters <= DBL_MIN || liters > DBL_MAX){
			printf("Invalid input, must be in [%f %f] interval.\n",
			 DBL_MIN, DBL_MAX);
		}
	}while (liters < DBL_MIN || liters > DBL_MAX);
	tot_liters+=liters;
	
	consume = kilometers / liters;
	printf("The km/l for this tank was: %.1lf\n", consume);  
	
	
	// elaborazione
	while (kilometers > 0) {
		
		printf("%s", "Enter km driven (-1 to end): ");
		do{
			scanf("%d", &kilometers);
			if(kilometers < INT_MIN || kilometers > INT_MAX){
				printf("Invalid input, must be in [%d, %d] interval.\n",
				 INT_MIN, INT_MAX);
			} 
		}while (kilometers < INT_MIN || kilometers > INT_MAX);
		if (kilometers == -1){
			break;
		}
		tot_kilometers+=kilometers;
		
		printf("%s", "Enter liters used: ");
		do{
			scanf("%lf", &liters);
			if(liters < DBL_MIN || liters > DBL_MAX){
				printf("Invalid input, must be in [%f %f] interval.\n",
				 DBL_MIN, DBL_MAX);
			}
		}while (liters < DBL_MIN || liters > DBL_MAX);
		tot_liters+=liters;
		
		consume = kilometers / liters;
		printf("The km/l for this tank was: %.1lf\n", consume);  
	}
	
	// calcolo del totale
	double overall_consume = tot_kilometers / tot_liters;
	printf("The overall km/l was: %.1lf", overall_consume);
	
	return 0;
}

