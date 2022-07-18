#include "lists.h"
/**
* sum_listint - function
* @head: pointer to first node of list
*
* Description: func to return the sum of all data(n) in listint_t.
* Return: sum of all data.
*/
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	int sum = 0;

	if (head == NULL || temp == NULL)
		return (0);
	while (temp != NULL)
	{
		sum = sum + temp->n;
		temp = temp->next;
	}
	return (sum);
}
