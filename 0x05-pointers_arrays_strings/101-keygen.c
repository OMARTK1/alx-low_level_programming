#include <stdio.h>
#include <stdlib.h>
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
	
	return (0);
}
