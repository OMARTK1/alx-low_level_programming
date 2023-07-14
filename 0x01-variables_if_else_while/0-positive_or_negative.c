#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: This program will assign a random number to the variable 'n'.
 *
 * Return: Always 0 (Success)
*/

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	printf("%d is\n", n);

	if (n > 0)
		printf("positive");
	else if (n == 0)
		printf("zero");
	else
		printf("negative");

	return (0);
}
