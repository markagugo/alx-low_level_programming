#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: a pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t n_nodes = 0;

	if (!h)
		return (0);
	while (h->prev)
		h = h->prev;

	while (h)
	{
		printf("%d\n", h->n);
		n_nodes++;
		h = h->next;
	}

	return (n_nodes);
}
