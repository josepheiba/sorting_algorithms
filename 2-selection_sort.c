#include "sort.h"

/**
 * selection_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
  int i, j, outer_layer, ol_idx;

  if (size < 2)
    return;

  for (i = 0; i < (int)size; i++)
  {
    outer_layer = array[i];
    ol_idx = i;
    for (j = 1 + i; j < (int)size; j++)
    {
      if (array[j] < outer_layer)
      {
        outer_layer = array[j];
        ol_idx = j;
      }
    }
    array[ol_idx] = array[i];
    array[i] = outer_layer;
    if (ol_idx != i)
      print_array(array, size);
  }
}
