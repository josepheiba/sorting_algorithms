#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

void swap_nodes(listint_t *node_prev, listint_t *node, listint_t **list);
void swap_nodes_2(listint_t *node_prev, listint_t *node, listint_t **list);
void q_sort(int *array, int l, int r, size_t size);
void m_sort(int *array, size_t start, size_t end, size_t size);
int partition(int *array, int l, int r, size_t size);

void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i);
void swap(int *a, int *b);
void compare_swap(int *array, size_t i, size_t j, int dir);
void bitonic_merge(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort_recursive(int *array, size_t low, size_t cnt, int dir);
void bitonic_sort(int *array, size_t size);

void radix_sort(int *array, size_t size);

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

#endif
