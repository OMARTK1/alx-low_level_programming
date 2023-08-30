#include "lists.h"
#include <stddef.h>

/**
 * sum_listint - returns the sum of all the data (n) of a listint_t linked list
 * @head: its pointer to the head of that list
 * Return: the sum of all data in that list
 */
int sum_listint(listint_t *head)
{
	int sum_data = 0;

	while (head != NULL)
	{
		sum_data += head->n;
		head = head->next;
	}

	return (sum_data);
}
