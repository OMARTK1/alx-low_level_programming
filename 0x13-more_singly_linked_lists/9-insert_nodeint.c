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
	listint_t *ins_at_ind = malloc(sizeof(listint_t));

	if (ins_at_ind == NULL)
		return (NULL);

	ins_at_ind->n = n;

	if (idx == 0)
	{
		ins_at_ind->next = *head;
		*head = ins_at_ind;
		return (ins_at_ind);
	}

	listint_t *prev_ind = *head;

	for (unsigned int i = 0; i < idx - 1 && prev_ind != NULL; i++)
		prev_ind = prev_ind->next;

	if (prev_ind == NULL)
	{
		free(ins_at_ind);
		return (NULL);
	}

	ins_at_ind->next = prev_ind->next;
	prev_ind->next = ins_at_ind;

	return (ins_at_ind);
}
