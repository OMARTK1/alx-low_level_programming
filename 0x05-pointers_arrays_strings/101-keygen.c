#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 11

int main(void)
{
	FILE *fp;
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

	/* Save the generated password to a file */
	fp = fopen("password.txt", "w");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Unable to open file for writing.\n");
		return (1);
	}
	
	fprintf(fp, "%s\n", password);
	fclose(fp);
	
	return (0);
}
