#include "sort.h"
#include <stdio.h>

/**
 * quick_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: The array to be printed
 */
void quick_sort(int *array, size_t size)
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

	pivot = array[r];
	for (i = j = l; i < r; i++)
	{
		if (array[i] < pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j && array[i] != array[j])
				print_array(array, size);
			j++;
		}
	}
	tmp = array[j];
	array[j] = array[r];
	array[r] = tmp;
	if (j != r && array[j] != array[r])
		print_array(array, size);
	return (j);
}
