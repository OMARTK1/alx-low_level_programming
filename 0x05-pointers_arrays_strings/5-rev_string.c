#include "main.h"

/**
 * rev_string - Reverses a string.
 *
 * @s: Pointer to the string to be reversed.
 */

void rev_string(char *s)
{
	if (s == NULL)
		return;

	int len = 0;
	char *start, *end, temp;

	while (*s[len] != '\0')
	{
		len++;
		s++;
	}

	s  -= len;
	start = s;
	end = s + len - 1;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
