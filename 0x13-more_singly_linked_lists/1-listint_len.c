#include "lists.h"
#include <stddef.h>

/**
 * listint_len - it returns the number of elements in a linked listint_t list
 * @h: it pointers to head of that list
 * Return: number of elements in that list
 */
size_t listint_len(const listint_t *h)
{
	size_t num_elements = 0;

	while (h)
	{
		h = h->next;
		num_elements++;
	}
	return (num_elements);
}
