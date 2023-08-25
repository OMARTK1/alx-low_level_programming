#include "lists.h"

/**
 * print_list - it prints all the elements of a list_t list
 * @h: A pointer to the head node of the linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t num_nodes;

	num_nodes = 0;
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next;
		num_nodes++;
	}

	return (num_nodes);
}
