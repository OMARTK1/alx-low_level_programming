#include "lists.h"

/**
 * add_node - it adds a new node at the beginning of a linked list
 * @head: A pointer to a pointer to the head node of the list
 * @str: The string to be stored in the new node
 *
 * Return: A pointer to the new node if successful,
 *		NULL if memory allocation fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;

	if (str == NULL)
		return (NULL);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->len = strlen(str);

	new_node->next = *head;
	*head = new_node;

	return (*head);
}
