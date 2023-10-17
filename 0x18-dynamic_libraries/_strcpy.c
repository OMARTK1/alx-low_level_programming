#include "main.h"

char *_strcpy(char *dest, char *src) {
	char *ptr = dest;
	while ((*dest++ = *src++))
		;
	return ptr;
}
