#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * add_nodeint_end - it adds a new node at the end of a listint_t list
 * @head: its double pointer to the head of that list
 * @n: the value to be stored in the new node
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_nodeInEnd = malloc(sizeof(listint_t));

	if (new_nodeInEnd == NULL)
		return (NULL);

	new_nodeInEnd->n = n;
	new_nodeInEnd->next = NULL;

	if (*head == NULL)
	{
		*head = new_nodeInEnd;
	}
	else
	{
		listint_t *current = *head;

		while (current->next != NULL)
			current = current->next;
		current->next = new_nodeInEnd;
	}

	return (new_nodeInEnd);
}
