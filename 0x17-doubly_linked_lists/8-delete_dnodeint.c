#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Pointer to the head of the doubly linked list.
 * @index: Index of the node that should be deleted. Index starts at 0.
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	if (*head == NULL)
		return -1;

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return 1;
	}

	while (current != NULL && i < index)
	{
		temp = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return -1;

	temp->next = current->next;
	if (current->next != NULL)
		current->next->prev = temp;
	free(current);
	return 1;
}
