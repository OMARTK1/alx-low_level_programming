#include <stdio.h>

/**
 * print_times_table - Prints the n times table
 *
 * @n: The number imput
*/

void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{

		for (j = 0; j <= n; j++)
		{

			int result = i * j;


			if (j != n)

				printf(", ");

			printf("%3d", result);
		}
		printf("\n");
	}
}
