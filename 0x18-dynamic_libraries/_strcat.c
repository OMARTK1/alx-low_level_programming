#include "main.h"

char *_strcat(char *dest, char *src) {
	char *ptr = dest;
	while (*dest)
		dest++;
	while ((*dest++ = *src++))
		;
	return ptr;
}
