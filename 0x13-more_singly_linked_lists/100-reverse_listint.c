#include "lists.h"


/**
 * reverse_listint - it reverses a listint_t linked list
 * @head: its double pointer to the head of that linked list
 * Return: the pointer to new head of a reversed linked list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current_n = NULL;

	while (*head)
	{
		current_n = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = current_n;
	}

	*head = prev;

	return (*head);
}
