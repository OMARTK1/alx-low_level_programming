#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - it inserts a new node at a given position
 * @head: its double pointer to the head of that list
 * @idx: the index of that list where the new node should be added,
 *		starts at 0
 * @n: the value to be stored in the new node
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int a;
	listint_t *new_node_post;
	listint_t *b;

	b = *head;

	if (idx != 0)
	{
		for (a = 0; a < idx - 1 && b != NULL; a++)
		{
			b = b->next;
		}
	}

	if (b == NULL && idx != 0)
		return (NULL);

	new_node_post = malloc(sizeof(listint_t));
	if (new_node_post == NULL)
		return (NULL);

	new_node_post->n = n;

	if (idx == 0)
	{
		new_node_post->next = *head;
		*head = new_node_post;
	}
	else
	{
		new_node_post->next = b->next;
		b->next = new_node_post;
	}
	return (new_node_post);
}
