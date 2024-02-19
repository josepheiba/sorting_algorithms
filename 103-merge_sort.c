#include "sort.h"
#include <stdio.h>
#include <sys/_types/_size_t.h>

/**
 * shell_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
  m_sort(array, 0, size - 1, size);
}

void m_sort(int *array, size_t start, size_t end, size_t size)
{
  size_t half, i, j, k;
  int *ar;
  int *ray;
  int *aray;

  if (start == end)
    return;

  half = ((end + start - 1) / 2);

  m_sort(array, start, half, size);
  m_sort(array, half + 1, end, size);

  ar = (int *)malloc(sizeof(int) * (half - start + 1));
  ray = (int *)malloc(sizeof(int) * (end - half));

  aray = (int *)malloc(sizeof(int) * (end - start + 1));

  for (i = start; i <= half; i++)
      ar[i - start] = array[i];

  for (i = half + 1; i <= end; i++)
      ray[i - half - 1] = array[i];

 printf("Merging...\n");
    printf("[left]: ");
    for (i = 0; i < half - start + 1; i++) // Use the loop variable 'i' defined outside
        printf("%d ", ar[i]);
    printf("\n");

    printf("[right]: ");
    for (j = 0; j < end - half; j++) // Use the loop variable 'j' defined outside
        printf("%d ", ray[j]);
    printf("\n");


  i = 0;
    j = 0;
    k = 0;

    while (i < (half - start + 1) && j < (end - half)) {
        if (ar[i] <= ray[j]) {
            aray[k] = ar[i];
            i++;
        } else {
            aray[k] = ray[j];
            j++;
        }
        k++;
    }

    while (i < (half - start + 1)) {
        aray[k] = ar[i];
        i++;
        k++;
    }

    while (j < (end - half)) {
        aray[k] = ray[j];
        j++;
        k++;
    }

    // Copy the merged array back to the original array
    for (i = start, k = 0; i <= end; i++, k++)
        array[i] = aray[k];

    printf("[Done]: ");
    for (i = 0; i < end - start + 1; i++)
        printf("%d ", aray[i]);
    printf("\n\n");

    // Free allocated memory for temporary arrays
    free(ar);
    free(ray);
    free(aray);

}
