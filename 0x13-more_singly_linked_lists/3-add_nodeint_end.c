#include "lists.h"
/**
* add_nodeint_end - function
* @head: double pointer - points to address of ptr to first element
* @n: integer value of new node
*
* Description: function to add new node at the end of a listint_t list
* Return: add of the new element, or NULL if fail
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp, *newNode;
	int num;

	num = n;
	newNode = (listint_t *)malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = num;
	newNode->next = NULL;
	if (*head == NULL)
		*head = newNode;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newNode;
	}
	return (newNode);
}
