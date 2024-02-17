#include "sort.h"

/**
 * insertion_sort_list - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *ll_ptr, *ll_ptr_idx; 

  if ((*list)->next == NULL || *list == NULL)
  {
    return;
  }

  ll_ptr = (*list)->next;
  while (ll_ptr != NULL)
  {
    ll_ptr_idx = ll_ptr->next;
    while (ll_ptr->prev != NULL && ll_ptr->n < ll_ptr->prev->n)
    {
      swap_nodes(ll_ptr->prev, ll_ptr, list);
      print_list(*list);
    }
    ll_ptr = ll_ptr_idx;
  }
}

/**
 * swap_nodes - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
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
