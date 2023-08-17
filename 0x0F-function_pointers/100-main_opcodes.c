#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point.
 * @argc: argument count.
 * @argv: argument vector.
 * Return: 0 on success, 1 on incorrect argument count,
 *         2 on negative number of bytes.
 */
int main(int argc, char *argv[])
{
	int num_bytes, i;
	unsigned char *main_addr;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	main_addr = (unsigned char *)main;

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", *(main_addr + i));
		if (i < num_bytes - 1)
			printf(" ");
	}
	printf("\n");

	return (0);
}
