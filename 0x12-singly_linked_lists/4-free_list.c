#include "lists.h"

/**
 * free_list - it frees a list_t list
 * @h: A pointer to the head node
 *
 * Return: void
 */
void free_list(list_t *h)
{
	list_t *i;

	while (h)
	{
		i = h->next;
		free(h->str);
		free(h);
		h = i;
	}
}
