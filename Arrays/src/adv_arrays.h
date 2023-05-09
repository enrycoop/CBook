/*
 * auto_array.h
 *
 *  Created on: 8 mag 2023
 *      Author: enric
 */

#ifndef ADV_ARRAYS_H_
#define ADV_ARRAYS_H_

#include <stdio.h>
#define SIZE 10


// function to demonstrate a static local array
void staticArrayInit(void) {
	// initializes elements to 0 before the function is called
	static int array1[3];

	puts("\nValues on entering staticArrayInit:");

	// output contents of array1
	for (size_t i = 0; i <= 2; ++i) {
		printf("array1[%zu] = %d  ", i, array1[i]);
	}

	puts("\nValues on exiting staticArrayInit:");

	// modify and output contents of array1
	for (size_t i = 0; i <= 2; ++i) {
		printf("array1[%zu] = %d  ", i, array1[i] += 5);
	}
}

void bubble_sort(int a[], size_t dim) {
	// bubble sort
	// loop to control number of passes
	for (int pass = 1; pass < dim; ++pass) {
		// loop to control number of comparisons per pass
		for (size_t i = 0; i < dim - 1; ++i) {
			// compare adjacent elements and swap them if first
			// element is greater than second element
			if (a[i] > a[i + 1]) {
				int hold = a[i];
				a[i] = a[i + 1];
				a[i + 1] = hold;
			}
		}
	}
}

//main
void static_array(void) {
	puts("First call to each function:");
	staticArrayInit();

	puts("\n\nSecond call to each function:");
	staticArrayInit();
	puts("");
}


void order_bubble() {
   int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

   puts("Data items in original order");

   // output original array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   }


   bubble_sort(a, SIZE);

   puts("\nData items in ascending order");

   // output sorted array
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   }

   puts("");
}



#endif /* ADV_ARRAYS_H_ */
