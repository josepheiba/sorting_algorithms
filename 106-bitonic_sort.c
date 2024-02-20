#include <stdio.h>
#include "sort.h"

void compare_swap(int *array, size_t i, size_t j, int dir)
{
    int temp;

    if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
    {
        // Swap
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        printf("Swapping: %d, %d\n", array[i], array[j]);
    }
}

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

void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir)
{
    size_t k;

    if (cnt > 1)
    {
        k = cnt / 2;
        bitonic_sort_recursive(array, low, k, 1); // Sort in ascending order
        bitonic_sort_recursive(array, low + k, k, 0); // Sort in descending order
        bitonic_merge(array, low, cnt, dir);
    }
}

void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}
