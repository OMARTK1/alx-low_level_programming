#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct list_s - A node structure for singly linked list.
 * @str: The string stored in the node (allocated with malloc)
 * @len: The length of the string
 * @next: A pointer to the next node in the list
 *
 * Description: This structure defines a singly linked list node,
 *		where each node contains a string, its length,
 *		and a pointer to the next node in the list
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
