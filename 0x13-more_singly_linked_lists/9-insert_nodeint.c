#include "lists.h"
/**
* insert_nodeint_at_index - function
* @head: double pointer to first node of list
* @idx: index where new node should be added
* @n: new node to insert
*
* Description: function to insert a new node at a given position
* Return: the address of the new node, or null if fail
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newNode, *temp;
	unsigned int num;

	if (head == NULL)
		return (NULL);

	newNode = (listint_t *)malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;

	if (idx == 0)
	{
		newNode->next = (*head);
		(*head) = newNode;
		return (newNode);
	}
	temp = *head;


		for (num = 2; num <= idx; num++)
		{

			if (temp == NULL)
				return (NULL);

			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
		return (newNode);
}
