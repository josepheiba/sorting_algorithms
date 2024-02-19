#include "sort.h"
#include <stdio.h>
#include <sys/_types/_size_t.h>

/**
 * quick_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: The array to be printed
 */
void quick_sort(int *array, size_t size)
{
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
void q_sort(int *array, size_t l, size_t r, size_t size)
{
  size_t p;

  if (l >= r)
    return;
  p = partition(array, l, r, size);
  if (p != 0)
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
size_t partition(int *array, size_t l, size_t r, size_t size)
{
  size_t pivot, i, j, tmp;

  pivot = (size_t)array[r];
  j = l;
  for (i = l; i < r; i++)
  {
    if ((size_t)array[i] < pivot)
    {
      tmp = array[i];
      array[i] = array[j];
      array[j] = tmp;
      if(i != j)
        print_array(array, size);
      j++;
    }
  }
  tmp = array[j];
  array[j] = array[r];
  array[r] = tmp;
  if(j != r)
    print_array(array, size);
  return(j);
}
