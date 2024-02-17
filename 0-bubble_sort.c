#include "sort.h"

/**
 * bubble_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
  int i, j, outer_layer;

  if (size < 2)
    return;

  for (i = size; i > 0; i--)
  {
    for (j = 0; j < i - 1; j++) {
      if (array[j] > array[j + 1]) {
        outer_layer = array[j + 1];
        array[j + 1] = array[j];
        array[j] = outer_layer;
        print_array(array, size);
      }
    }
  }
}
