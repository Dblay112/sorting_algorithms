#include "sort.h"

/**
 * exchange_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: pointer to the head of doubly-linked list.
 * @n1: pointer to the first node to exchange
 * @n2: second node to interchange
 */
void exchange_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function to sort using insertion
 * @list: pointer to the head of the doubly linkd list.
 *
 * Description: each interchange is printed.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *run, *insert, *ex;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (run = (*list)->next; run != NULL; run = ex)
	{
		ex = run->next;
		insert = run->prev;
		while (insert != NULL && run->n < insert->n)
		{
			exchange_nodes(list, &insert, run);
			print_list((const listint_t *)*list);
		}
	}
}
