#include "lists.h"

/**
 * print_list - it prints all the elements of a list_t list
 * @head: A pointer to the head node of the linked list
 *
 * Return: The number of nodes in the list
 */
size_t print_list(const list_t *head)
{
	size_t num_nodes;

	num_nodes = 0;
	while (head != NULL)
	{
		if (head->str == NULL)
			printf("[%d] %s\n", 0, "(nil)");
		else
			printf("[%d] %s\n", head->len, head->str);

		head = head->next;
		num_nodes++;
	}

	return (num_nodes);
}
