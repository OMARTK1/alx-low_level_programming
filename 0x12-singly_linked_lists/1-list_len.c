#include "lists.h"

/**
 * list_len - it counts the number of elements in a linked list
 * @h: A pointer to the head node of the linked list
 *
 * Return: The total number of elements in the list
 */
size_t list_len(const list_t *h)
{
	size_t element_count;

	element_count = 0;

	while (h != NULL)
	{
		h = h->next;
		element_count++;
	}

	return (element_count);
}
