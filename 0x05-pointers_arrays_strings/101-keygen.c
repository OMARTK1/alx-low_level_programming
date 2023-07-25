/**
 * main - Generates a random valid password for the program 101-crackme.
 *
 * Return: Always 0 (Success)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 13

/**
 * main - Generates a random valid password for the program 101-crackme.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator
	int i, sum, target;

	srand(time(0));

	sum = 2772; // Sum of ASCII values of the password "Tada! Congrats"
	target = PASSWORD_LENGTH;

	for (i = 0; i < PASSWORD_LENGTH - 1; i++)
	{
		// Generate a random ASCII value between 33 and 126
		int rand_char = rand() % (126 - 33 + 1) + 33;

		password[i] = rand_char;
		sum -= rand_char;
	}

	password[PASSWORD_LENGTH - 1] = sum;
	password[PASSWORD_LENGTH] = '\0';

	printf("%s\n", password);

	return (0);
}
