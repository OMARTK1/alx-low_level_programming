#include "lists.h"

/**
 * delete_nodeint_at_index - it deletes the node at a given index
 * @head: its pointer to a pointer to the head of that list
 * @index: th index of the node to delete, starts at 0
 * Return: 1 if success, -1 if failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *prev_node;
	listint_t *new_node_post;

	prev_node = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prev_node != NULL; i++)
		{
			prev_node = prev_node->next;
		}
	}

	if (prev_node == NULL || (prev_node->next == NULL && index != 0))
	{
		return (-1);
	}

	new_node_post = prev_node->next;

	if (index != 0)
	{
		prev_node->next = new_node_post->next;
		free(new_node_post);
	}
	else
	{
		free(prev_node);
		*head = new_node_post;
	}

	return (1);
}
