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
	if (!array || !size)
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
    int pivot = array[r];
    int j;
    int i = l - 1;

    for (j = l; j < r; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                // Swap array[i] and array[j]
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                print_array(array, size); // Assuming this function is implemented elsewhere
            }
        }
    }
    // Swap the pivot to its correct position
    if (i + 1 != r)
    {
        int tmp = array[i + 1];
        array[i + 1] = array[r];
        array[r] = tmp;
        print_array(array, size); // Assuming this function is implemented elsewhere
    }
    return i + 1;
}
