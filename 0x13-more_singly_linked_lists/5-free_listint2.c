#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - it frees a listint_t list and sets the head to NULL
 * @head: its double pointer to the head of that list
 */
void free_listint2(listint_t **head)
{
	if (head == NULL)
		return;

	listint_t *empty_list2 = *head;

	while (empty_list2 != NULL)
	{
		listint_t *temp = empty_list2;

		empty_list2 = empty_list2->next;
		free(temp);
	}

	*head = NULL;
}
