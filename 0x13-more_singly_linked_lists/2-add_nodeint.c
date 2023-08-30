#include "lists.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * add_nodeint - it adds a new node at the beginning of a listint_t list
 * @head: its double pointer to the head of that list
 * @n: the value to be stored in the new node
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add_new_node = malloc(sizeof(listint_t));

	if (add_new_node == NULL)
		return (NULL);

	add_new_node->n = n;
	add_new_node->next = *head;
	*head = add_new_node;

	return (*head);
}
