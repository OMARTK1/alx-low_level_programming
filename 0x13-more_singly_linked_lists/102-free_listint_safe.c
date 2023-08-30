#include "lists.h"
#include <stdlib.h>
/**
 * free_listint_safe - it frees a listint_t linked list safely
 * @h: its double pointer to the head of that list
 *
 * Return: Size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t node_count = 0;
	listint_t *temp; *current;

	if (h == NULL || *h == NULL)
		return (node_count);

	current = *h;
	while (current != NULL)
	{
		node_count++;
		temp = current;
		current = current->next;
		free(temp);
		if (temp <= current)
			break;
	}

	*h = NULL;

	return (node_count);
}
