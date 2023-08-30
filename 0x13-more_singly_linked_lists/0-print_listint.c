#include "lists.h"
#include <stddef.h>

/**
 * print_listint - it prints all the elements of a list
 * @h: it pointers to the head of that list
 *
 * Return: The number of nodes in that list
 */
size_t print_listint(const listint_t *h)
{
	size_t Num_nodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		Num_nodes++;
	}

	return (Num_nodes);
}
