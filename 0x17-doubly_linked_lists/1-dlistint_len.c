#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a doubly linked list
 * @h: a pointer to the head node of the list
 * Return: the number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t len = 0;

	if (!h)
		return (0);
	while (h->prev)
		h = h->prev;
	while (h)
	{
		len++;
		h = h->next;
	}

	return (len);
}
