#include "lists.h"

/**
 * print_listint_safe - it prints a listint_t linked list safely
 * @head: its pointer to the head of that list
 *
 * Return: Number of nodes in that list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count_node = 0;
	const listint_t *temp, *current;

	current = head
	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		node_count++;
		temp = current;
		current = current->next;

		if (temp <= current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
	}

	return (node_count);
}
