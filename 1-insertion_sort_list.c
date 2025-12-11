#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: pointer to the start of the list
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev_node, *next_node;

	if (node1 == NULL || node2 == NULL)
		return;

	if (node1 == node2)
		return;

	prev_node = node1->prev;
	next_node = node2->next;

	if (prev_node != NULL)
		prev_node->next = node2;
	node2->prev = prev_node;

	node2->next = node1;
	node1->prev = node2;

	node1->next = next_node;
	if (next_node != NULL)
		next_node->prev = node1;

	if (*list == node1)
		*list = node2;

	print_list(*list);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer to the start of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev_node = current->prev;

		while (prev_node != NULL && current->n < prev_node->n)
		{
			swap_nodes(list, prev_node, current);
			prev_node = current->prev;
		}

		current = current->next;
	}
}
