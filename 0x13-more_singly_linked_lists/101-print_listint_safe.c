#include "lists.h"

/**
 * print_listint_safe - it prints a listint_t linked list safely
 * @head: its pointer to the head of that list
 * Return: Number of nodes in that list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t Num_nodes = 0;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;
		Num_nodes++;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			break;
		}
	}

	return (Num_nodes);
}
