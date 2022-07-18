#include "lists.h"
/**
* free_listint - function
* @head: ptr to beginning of list
*
* Description: function to free list
* Return: 0
*/
void free_listint(listint_t *head)
{
	listint_t *temp = head; /* Will store head ->next*/

	if (head == NULL)
		return;
	while (head->next != NULL)
	{
		temp = head;
		/* free the stuff inside what head is pointing to*/
		head = head->next;
		free(temp); /* goes to next node in list and repeat process*/
	}
	free(head);
}
