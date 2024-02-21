#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_hoare - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: The array to be printed
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;

	q_sort(array, 0, size - 1, size);
}

/**
 * q_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @l: The array to be printed
 * @r: The array to be printed
 * @size: The array to be printed
 */
void q_sort(int *array, int l, int r, size_t size)
{
	int p;

	if (l >= r)
		return;
	p = partition(array, l, r, size);
	q_sort(array, l, p - 1, size);
	q_sort(array, p + 1, r, size);
}

/**
 * partition - Prints an array of integers
 *
 * @array: The array to be printed
 * @l: The array to be printed
 * @r: The array to be printed
 * @size: The array to be printed
 *
 * Return: index of the pivot element after partitioning
 */
int partition(int *array, int l, int r, size_t size)
{
	int pivot, i, j, tmp;

	i = l - 1;
	j = r + 1;
	pivot = array[r];

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i < j)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
	return (i);
}
