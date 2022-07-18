#include "lists.h"
/**
* listint_len - function
* @h: string to print
*
* Description: Fnction to count nodes of the list_t list.
* Return: number of nodes
*/
size_t listint_len(const listint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
