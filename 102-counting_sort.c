#include "sort.h"
#include <stdlib.h>

/**
 * shell_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size) {
    size_t i;
    int max_num, current_num, duplicate;
    int *counts;
    int *sorted_array;

    if (array == NULL || size < 2)
        return;

    // Find the maximum number in the array to determine the size of the counts array
    max_num = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max_num)
            max_num = array[i];
    }

    // Allocate memory for counts array and initialize to 0
    counts = (int*)malloc(sizeof(int) * (size_t)(max_num + 1));
    if (counts == NULL)
        return;

    for (i = 0; i < (size_t)(max_num + 1); i++)
        counts[i] = 0;

    // Count occurrences of each element in the array
    for (i = 0; i < size; i++) {
        current_num = array[i];
        counts[current_num]++;
    }

    // Update counts array to hold the actual positions of elements
    for (i = 1; i < (size_t)(max_num + 1); i++)
        counts[i] += counts[i - 1];

    print_array(counts, max_num + 1);

    // Rearrange the elements based on counts
    sorted_array = (int*)malloc(sizeof(int) * size);
    if (sorted_array == NULL) {
        free(counts);
        return;
    }

    for (i = 0; i < size; i++) {
        current_num = array[i];
        duplicate = counts[current_num] - 1;
        sorted_array[duplicate] = current_num;
        counts[current_num]--;
    }

    // Copy sorted elements back to the original array
    for (i = 0; i < size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(counts);
}
