#include "lists.h"

/**
 * add_node_end - it adds a new node at the end of a linked list
 * @h: A pointer to a pointer to the head node of the list
 * @str: The string to be duplicated and stored in the new node
 *
 * Return: A pointer to the new node if successful,
 *		NULL if memory allocation fails
 */
list_t *add_node_end(list_t **h, const char *str)
{
	list_t *new_node;
	list_t *temp = *h;
	unsigned int len = 0;

	while (str[len])
		len++;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	new_node->len = len;
	new_node->next = NULL;

	if (*h == NULL)
	{
		*h = new_node;
		return (new_node);
	}

	while (temp->next)
		temp = temp->next;

	temp->next = new_node;

	return (new_node);
}
