#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Prints an array of integers
 *
 * @list: The array to be printed
 */
void quick_sort(int *array, size_t size)
{
  q_sort(array, 0, (long int)size - 1, size);
}

/**
 * q_sort - Prints an array of integers
 *
 * @l: The array to be printed
 * @r: The array to be printed
 * @size: The array to be printed
 */
void q_sort(int *array, long int l, long int r, size_t size)
{
  long int p;

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
 */
long int partition(int *array, long int l, long int r, size_t size)
{
  long int pivot, i, j, tmp;

  pivot = array[r];
  j = l - 1;
  for (i = l; i < r; i++)
  {
    if (array[i] < pivot)
    {
      j++;
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      if(i != j)
        print_array(array, size);
    }
  }
  j++;
  tmp = array[j];
  array[j] = array[r];
  array[r] = tmp;
  if(j != r)
    print_array(array, size);
  return(j);
}
