#include "sort.h"

/**
 * swap_nodes - swaps nodes in doubly linked lists
 * @list: pointer to head of list
 * @node1: first node to swap
 * @node2: second node to swap
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || !list || node1 == node2)
	{
		return;
	}
	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (node2->next)
	{
		node2->next->prev = node1;
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Head of list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		while (current->prev && current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			print_list(*list);
		}
		current = next_node;
	}
}
