#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - it frees a listint_t list and sets the head to NULL
 * @head: its double pointer to the head of that list
 */
void free_listint2(listint_t **head)
{
	listint_t *empty_listl;

	if (head == NULL)
		return;

	while (*head)
	{
		empty_list = (*head)->next;
		free(*head);
		*head = empty_list;
	}
	*head = NULL;
}
