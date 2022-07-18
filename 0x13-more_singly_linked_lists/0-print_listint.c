#include "lists.h"
/**
* print_listint - function
* @h: string to print
*
* Description: Fnction to print all elements in listint_t
* Return: number of nodes
*/
size_t print_listint(const listint_t *h)
{
	int elements = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		elements++;
	}
	return (elements);
}
