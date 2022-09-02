#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: the pointer to the starting node
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	if (!head)
		return;

	while (head->prev)
		head = head->prev;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
