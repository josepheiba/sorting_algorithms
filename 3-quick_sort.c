#include "sort.h"
#include <stdio.h>

void swap_ints(int *x, int *y)
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int pivot, i, j;

    pivot = array[right];
    i = left - 1;

    for (j = left; j <= right - 1; j++) {
        if (array[j] < pivot) {
            i++;
            swap_ints(&array[i], &array[j]);
            print_array(array, size);
        }
    }

    swap_ints(&array[i + 1], &array[right]);
    print_array(array, size);

    return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (left < right) {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm
 * @array: An array of integers
 * @size: The size of the array
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}
