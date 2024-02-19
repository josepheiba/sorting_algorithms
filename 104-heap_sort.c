#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Performs the sift-down operation on a binary heap
 * @array: Array to be sorted
 * @start: Index of the root of the heap
 * @end: Index of the end of the heap
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while ((root * 2) + 1 <= end)
	{
		size_t child = (root * 2) + 1;
		size_t swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;

		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
			return;

		swap(&array[root], &array[swap_index]);
		print_array(array, size);
		root = swap_index;
	}
}

/**
 * heap_sort - Sorts an array of intege
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	size_t j;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, i, size - 1, size);
	}

	for (j = size - 1; j > 0; j--)
	{
		swap(&array[0], &array[j]);
		print_array(array, size);
		sift_down(array, 0, j - 1, size);
	}
}
