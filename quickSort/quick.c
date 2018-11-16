#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arrayShift(int array[], int start, int end) {
	int index;

	for(index = end; index > start; index--)
		array[index] = array[index-1];
}

int quickDivide(int array[], int end, int pivot) {
	int index, tempIndex;
	int temp;

	for(index = pivot + 1; index < end; index++) {
		if(array[pivot] >= array[index]) {
			temp = array[index];
			arrayShift(array, pivot, index);
			array[pivot] = temp;
			pivot++;
		}
	}
	return pivot;
}

void quickSort(int array[], int start, int end) {
	int pivot = start;
	
	if(end - start <= 1)
		return ;

	pivot = quickDivide(array, end, pivot);

	quickSort(array, start, pivot);
	quickSort(array, pivot+1, end);
}

int main(void) {
	int array[SIZE];
	int index;

	srand(time(NULL));

	for(index = 0; index < SIZE; index++) 
		array[index] = rand()%(SIZE+5);

	for(index = 0; index < SIZE; index++)
		printf("%3d", array[index]);
	printf("\n");

	quickSort(array, 0, SIZE);

	for(index = 0; index < SIZE; index++)
		printf("%3d", array[index]);
	printf("\n");

	return 0;
}