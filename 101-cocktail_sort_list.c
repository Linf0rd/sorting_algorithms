#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: Pointer to the head of the list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 *
 * Description: This function swaps the positions of two nodes
 *		in a doubly linked list.
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the
 *			cocktail shaker sort algorithm.
 *
 * @list: Pointer to the head of the list.
 *
 * Description: This function sorts a doubly linked list in
 *		ascending order using the cocktail shaker sort algorithm.
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		temp = current;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				temp = temp->prev;
			}
		}
	}
}
