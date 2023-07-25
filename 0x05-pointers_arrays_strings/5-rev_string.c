#include "main.h"
/**
 * rev_string - Reverses a string.
 *
 * @s: Pointer to the string to be reversed.
 */

void rev_string(char *s)
{

	int len = 0;
	char *start = s;
	char *end = s;
	char temp;

	if (s == NULL)
		return;

	while (*end != '\0')
	{
		end++;
		len++;
	}

	end--;

	while (start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}
