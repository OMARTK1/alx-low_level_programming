#include "main.h"

char *_strncpy(char *dest, char *src, int n) {
	char *ptr = dest;
	while (n-- && (*dest++ = *src++))
		;
	while (n-- > 0)
		*dest++ = '\0';
	return ptr;
}
