/*Given an array (or string), the task is to reverse the array/string*/

#include <stdio.h>

void printArray(int *arr, int size)
{		
	for (int i = 0; i < size; i++) { 
		printf("%d\n", arr[i]);
	}
}

int* reverseArray(int *arr, int size)
{
	int start = 0, end = size - 1;

	while (start < end) {
		int aux    = arr[start];
		arr[start] = arr[end];
		arr[end]   = aux;

		start++;
		end--;
	}	
	return arr;
}

int main() 
{
	int arr[] = {1, 2, 3, 4, 5};
	int *ptr  = arr;
	int size  = sizeof(arr) / sizeof(arr[0]);
		
	ptr = reverseArray(ptr, size);
	printArray(ptr, size);
}
