#include "lists.h"
/**
* free_listint2 - function
* @head: ptr to ptr to beginning of list
*
* Description: function to free list
* Return: 0
*/
void free_listint2(listint_t **head)
{
	listint_t *temp; /* Will store head ->next*/

	if (!head)
		return;
	while (*head != NULL)
	{
		temp = (*head)->next;
		/* free the stuff inside what head is pointing to*/
		free(*head);
		(*head) = temp; /* goes to next node in list and repeat process*/
	}
	head = NULL;
}
