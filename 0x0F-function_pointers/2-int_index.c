#include "function_pointers.h"
/**
 * int_index - searches for an integer in an array
 * @array: pointer to the array to be searched
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 * Return: Index of the first matching element,
 * or -1 if not found or invalid size
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array != NULL && size > 0 && cmp != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}
