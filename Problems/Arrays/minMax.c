/*Given an array of size N. Find the maximum and the minimum element of the array*/

#include <stdio.h>
#include <stdlib.h>

int* findMinMax(int arr[], int size)
{
	int min, max = 0, *result;
	result = (int *)malloc(2*sizeof(int));
	
	min = arr[0];
	for (int i = 0; i < size; i++) {
		
		if (arr[i] > max)
			max = arr[i];

		if (arr[i] < min) // fix
			min = arr[i];	
	}

	result[0] = min;
	result[1] = max;
	return result;
}

int main() 
{
	int arr[] = {5, 7, 4, 0, 1, 12, 3};
	int *r;

	r = findMinMax(arr, 7);
	printf("Min: %d; Max: %d\n", r[0], r[1]);

	free(r);
}
