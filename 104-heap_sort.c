#include "sort.h"

/**
 * heap_sort - order using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		heapify(array, size, i);
		print_array(array, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
		print_array(array, size);
	}
}

/**
 * heapify - Repair the heap whose root element is at index 'i'
 * @array: Array to be sorted
 * @size: Size of the array
 * @i: Index of the root element of the subtree
 */
void heapify(int *array, size_t size, size_t i)
{
	int temp;

	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		heapify(array, size, largest);
	}
}
