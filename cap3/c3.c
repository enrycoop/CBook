/*
 * hello.c
 * 
 * Copyright 2023 Sergio Enrico Coppolecchia <enrico@ThinkPad>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <limits.h>

int main(int argc, char **argv)
{
	// inizializza le variabili nelle definizioni
	int total = 0;
	int counter = 0;
	printf("This program makes avg of grades([%d,%d])\n",INT_MIN,INT_MAX);
	// elaborazione
	printf("%s", "Enter grade, -1 to end: ");
	int grade = 0;
	do{
		scanf("%d", &grade);
	}while (grade > INT_MAX && grade < INT_MIN);
	
	while (grade != -1) {
		total += grade;
		++counter;
		
		printf("%s", "Enter grade, -1 to end: ");
		do{
			scanf("%d", &grade);
		}while (grade > INT_MAX && grade < INT_MIN); // input sicuro
		
	}
	
	// fae di chiusura
	if (counter != 0) {
		double average = (double) total / counter;
		
		printf("Class average is %.2f\n", average);
	}else{
		puts("No grades were entered");
	}
}

