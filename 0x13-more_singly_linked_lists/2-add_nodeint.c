#include "lists.h"
/**
* add_nodeint - function
* @head: list to add to
* @n: integer value of new node
*
* Description: Fnction to add node to the listint_t.
* Return: address of new element or NULL if fail
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newNode;
	int num;

	num = n;
	newNode = (listint_t *)malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = num;
	newNode->next = *head;
	*head = newNode;
	return (newNode);
}
