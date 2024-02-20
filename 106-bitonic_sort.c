#include <stdio.h>
#include "sort.h"

/**
 * compare_swap - Swaps two elements if they're out of order.
 * @array: Pointer to the array.
 * @i: Index of the first element.
 * @j: Index of the second element.
 * @dir: Sorting direction (ascending or descending).
 **/
void compare_swap(int *array, size_t i, size_t j, int dir)
{
	int temp;

	if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		printf("Swapping: %d, %d\n", array[i], array[j]);
	}
}

/**
 * bitonic_merge - Merges two subarrays into a bitonic sequence.
 * @array: Pointer to the array.
 * @low: Index of the first element of the first subarray.
 * @cnt: Number of elements in each subarray.
 * @dir: Sorting direction (ascending or descending).
 **/
void bitonic_merge(int *array, size_t low, size_t cnt, int dir)
{
	size_t k, i;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = low; i < low + k; i++)
			compare_swap(array, i, i + k, dir);
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sic sort algorithm.
 * @array: Pointer to the array.
 * @low: Index of the first element of the subarray.
 * @cnt: Number of elements in the subarray.
 * @dir: Sorting direction (ascending or descending).
 **/
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir)
{
	size_t k;

	if (cnt > 1)
	{
		k = cnt / 2;
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, cnt, dir);
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic sort algorithm.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 **/
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}
