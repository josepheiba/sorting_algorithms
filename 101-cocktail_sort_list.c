#include "sort.h"

/**
 * cocktail_sort_list - Prints an array of integers
 *
 * @list: The array to be printed
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ll_ptr, *right_ptr, *left_ptr;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	right_ptr = left_ptr = NULL;
	ll_ptr = (*list);
	do {
		while (ll_ptr != right_ptr && ll_ptr->next != NULL)
		{
			if (ll_ptr->n > ll_ptr->next->n)
			{
				swap_nodes(ll_ptr, ll_ptr->next, list);
				print_list(*list);
			}
			else
				ll_ptr = ll_ptr->next;
		}
		ll_ptr = ll_ptr->prev;
		right_ptr = ll_ptr;

		while (ll_ptr != left_ptr && ll_ptr->prev != NULL)
		{
			if (ll_ptr->n < ll_ptr->prev->n)
			{
				swap_nodes(ll_ptr->prev, ll_ptr, list);
				print_list(*list);
			}
			else
				ll_ptr = ll_ptr->prev;
		}
		ll_ptr = ll_ptr->next;
		left_ptr = ll_ptr;
	} while (left_ptr != NULL && right_ptr != NULL && left_ptr != right_ptr && left_ptr->next != NULL && right_ptr->prev != NULL);
}

/**
 * swap_nodes - Prints an array of integers
 *
 * @node_prev: The array to be printed
 * @node: Number of elements in @array
 * @list: Number of elements in @array
 */
void swap_nodes(listint_t *node_prev, listint_t *node, listint_t **list)
{
	listint_t *node_next = NULL;

	node_next = node->next;

	if (node_prev->prev != NULL)
		node_prev->prev->next = node;
	else
		*list = node;
	node->prev = node_prev->prev;

	node->next = node_prev;
	node_prev->prev = node;

	node_prev->next = node_next;
	if (node_next != NULL)
		node_next->prev = node_prev;
}
