#include "lists.h"

/**
 * free_listint - it frees a listint_t list
 * @head: its pointer to the head of that list
 * Return: void
 */
void free_listint(listint_t *head)
{
	listint_t *empty_list;

	while (head != NULL)
	{
		empty_list = head;
		head = head->next;
		free(empty_list);
	}
}
