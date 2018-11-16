#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20000

void arrayShift(int array[], int start, int end) {
	int index;

	for(index = end; index > start; index--)
		array[index] = array[index-1];
}

void mergeConcat(int array[], int start, int center, int end) {
	int pivot = start;
	int arr1Index = start, arr2Index = center;
	int temp;

	for( ; pivot < end; pivot++) {
		if(arr1Index < center && arr2Index < end) {
			if(array[arr1Index] <= array[arr2Index])
				arr1Index+=1;
			else {
				temp = array[arr2Index];
				arrayShift(array, pivot, arr2Index);
				array[pivot] = temp;
				arr1Index+=1;
				arr2Index+=1;
				center+=1;
			}
		}
		else if(arr1Index < center)
			array[pivot] = array[arr1Index++];
		else if(arr2Index < end)
			array[pivot] = array[arr2Index++];
	}
}

void mergeDivide(int array[], int start, int end) {
	int center;

	if(end - start <= 1)
		return ;

	center = (start + end) / 2;

	mergeDivide(array, start, center);
	mergeDivide(array, center, end);

	mergeConcat(array, start, center, end);
}

int main(void) {
	int array[SIZE];
	int index;

	srand(time(NULL));

	for(index = 0; index < SIZE; index++) 
		array[index] = rand()%(SIZE+1);

	for(index = 0; index < SIZE; index++)
		printf("%3d", array[index]);
	printf("\n");

	mergeDivide(array, 0, SIZE);

	for(index = 0; index < SIZE; index++)
		printf("%3d", array[index]);
	printf("\n");

	return 0;
}