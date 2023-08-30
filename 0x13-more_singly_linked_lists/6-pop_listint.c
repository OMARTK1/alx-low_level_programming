#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - it deletes the head node of a listint_t linked list
 * @head: its double pointer to the head of that list
 * Return: The head node's data (n)
 */
int pop_listint(listint_t **head)
{
	int data_h_node = 0;

	if (*head != NULL)
	{
		listint_t *temp = *head;

		data_h_node = temp->n;
		*head = temp->next;
		free(temp);
	}

	return (data_h_node);
}
