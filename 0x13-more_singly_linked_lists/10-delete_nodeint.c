#include "lists.h"

/**
 * delete_nodeint_at_index - it deletes the node at a given index
 * @head: its pointer to a pointer to the head of that list
 * @index: th index of the node to delete, starts at 0
 * Return: 1 if success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		listint_t *temp = *head;

		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *prev_indx = *head;
	listint_t *rmv_at_index = (*head)->next;

	for (unsigned int i = 1; i < index; i++)
	{
		if (rmv_at_index == NULL)
			return (-1);
		prev_indx = rmv_at_index;
		rmv_at_index = rmv_at_index->next;
	}

	prev_indx->next = rmv_at_index->next;
	free(rmv_at_index);
	return (1);
}
