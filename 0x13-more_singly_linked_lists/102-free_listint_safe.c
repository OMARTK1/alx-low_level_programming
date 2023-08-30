#include "lists.h"

/**
 * free_listint_safe - it frees a listint_t linked list safely
 * @h: its double pointer to the head of that list
 * Return: Size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t Num_nodes = 0;
	listint_t *temp;

	while (*h != NULL)
	{
		Num_nodes++;
		temp = *h;
		*h = (*h)->next;
		free(temp);

		if (temp == *h)
		{
			*h = NULL;
			break;
		}
	}

	return (Num_nodes);
}
