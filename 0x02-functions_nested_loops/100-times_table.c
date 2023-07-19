#include <stdio.h>

/**
 * print_times_table - Prints the n times table
 * @n: The number for which the times table is printed
 *
 * Return: void
*/

void print_times_table(int n)
{
	if (n < 0 || n > 15)
		return;

	int i, j;

	for (i = 0; i <= n; i++)
	{

		for (j = 0; j <= n; j++)
		{

			int result = i * j;

			printf("%d", result);

			if (j != n)
			{
				printf(", ");

				if (result < 10)
					printf(" ");
			}
		}
		printf("\n");
	}
}
