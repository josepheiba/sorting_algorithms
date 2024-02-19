#include "sort.h"

/**
 * shell_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
  size_t i, j, interval;
  int temp;

  if (array == NULL || size < 2)
	  return;

  interval = 0;
  while (interval < size / 3)
		interval = (interval * 3) + 1;

	while (interval != 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval /= 3;
	}
}
