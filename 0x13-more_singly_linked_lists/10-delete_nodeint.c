#include "lists.h"
/**
* delete_nodeint_at_index - function
* @head: double pointer to first node of list
* @index: index of node that should be deleted
*
* Description: function to dlete the node at index of a listint_t list
* Return: 1 is success, -1 if fail
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *temp2;
	unsigned int ind = 0;

	if (head == NULL)
		return (-1);

	temp = *head;
	if (index == 0 && *head != NULL)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}
	while (temp != NULL && ind < index)
	{
		ind++;
		if (ind == index)
		{
			temp2 = temp->next;
			temp->next = temp2->next;
			free(temp2);
			return (1);
		}
		temp = temp->next;
	}
	return (1);
}
