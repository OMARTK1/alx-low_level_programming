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
	listint_t *new_node_set = malloc(sizeof(listint_t));

	if (new_node_set == NULL)
		return (NULL);

	new_node_set->n = n;

	if (idx == 0)
	{
		new_node_set->next = *head;
		*head = new_node_set;
		return (new_node_set);
	}

	listint_t *prev = *head;

	for (unsigned int i = 0; i < idx - 1 && prev != NULL; i++)
		prev = prev->next;

	if (prev == NULL)
	{
		free(new_node_set);
		return (NULL);
	}

	new_node_set->next = prev->next;
	prev->next = new_node_set;

	return (new_node_set);
}
