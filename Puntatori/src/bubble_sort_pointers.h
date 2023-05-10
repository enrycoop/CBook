/*
 * bubble_sort_pointers.h
 *
 *  Created on: 10 mag 2023
 *      Author: enric
 */

#ifndef BUBBLE_SORT_POINTERS_H_
#define BUBBLE_SORT_POINTERS_H_

#define SIZE 10

void bubbleSort(int * const array, size_t size);
void printArray(const int* const array, size_t size);



void bubble_sort_main(void) {
	int a[SIZE] = {2, 6, 4, 8, 10, 12 , 89, 68, 45, 37 };

	puts("Data items in original order.");
	printArray(a, SIZE);

	bubbleSort(a, SIZE);

	puts("Data items in ascending order.");
	printArray(a, SIZE);

}

void bubbleSort(int* const array /*notazione equivalente a int array[]*/, size_t size){
	void swap (int* element1Ptr, int* element2Ptr); // prototipo

	for (int i = 0; i < size -1; ++i) {
		for (int j = 0; j < size - 1; ++j) {
			if (array[j] > array [j +1]) {
				swap(&array[j], &array[j + 1]); //passiamo per riferimento poiché di default il c passa gli elementi dell'array per valore
			}
		}
	}

}

void swap (int* element1Ptr, int* element2Ptr) {
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}


void printArray(const int* const array, size_t size) {
	printf("%s", "[ ");
	for (int i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	puts("]");
}




#endif /* BUBBLE_SORT_POINTERS_H_ */
