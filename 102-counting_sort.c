#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: array of integers to be sorted
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
    size_t i;
    int max_num, current_num, duplicate;
    int *counts;
    int *sorted_array;

    if (array == NULL || size < 2)
        return;

    max_num = array[0];
    for (i = 1; i < size; i++)
    {
        if (array[i] > max_num)
            max_num = array[i];
    }

    counts = malloc(sizeof(int) * (size_t)(max_num + 1));
    if (counts == NULL)
        return;

    for (i = 0; i < (size_t)(max_num + 1); i++)
        counts[i] = 0;

    for (i = 0; i < size; i++)
    {
        current_num = array[i];
        counts[current_num]++;
    }

    for (i = 1; i < (size_t)(max_num + 1); i++)
        counts[i] += counts[i - 1];

    print_array(counts, max_num + 1);

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
    {
        free(counts);
        return;
    }

    for (i = 0; i < size; i++)
    {
        current_num = array[i];
        duplicate = counts[current_num] - 1;
        sorted_array[duplicate] = current_num;
        counts[current_num]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(counts);
}
