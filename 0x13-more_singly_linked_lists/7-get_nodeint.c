#include "lists.h"

/**
 * get_nodeint_at_index - it returns the nth node of a listint_t linked list
 * @head: its pointer to the head of that list
 * @index: its the ondex of the node, starting at 0
 * Return: the pointer to the nth node, or NULL if the node does not exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int nth_node = 0;

	while (head != NULL)
	{
		if (nth_node == index)
			return (head);
		head = head->next;
		nth_node++;
	}

	return (NULL);
}
