#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 11

int main(void)
{
	char password[PASSWORD_LENGTH + 1]; /* +1 for the null terminator */
	const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	int i;
	
	srand(time(NULL)); /* Seed the random number generator with the current time */
       
	/* Generate random characters for the password */
	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		password[i] = charset[rand() % (sizeof(charset) - 1)];
	}
	
	password[PASSWORD_LENGTH] = '\0'; /* Null-terminate the password string */
	
	printf("%s\n", password);

	/* Run the 101-crackme program with the generated password as input */
	FILE *fp;
	char command[50];
	char output[50];

	sprintf(command, "./101-crackme \"%s\"", password);
	fp = popen(command, "r");

	if (fp == NULL)
	{
		perror("popen");
		exit(EXIT_FAILURE);
	}

	fgets(output, sizeof(output), fp);

	pclose(fp);

	/* Check if the output matches the expected output */
	if (strcmp(output, "Tada! Congrats\n") == 0)
	{
		printf("Correct output: Compare with solution\n");
	}
	else
	{
		printf("Wrong password\n");
	}

	return (0);
}
