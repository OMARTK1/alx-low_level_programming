#include "main.h"

char *_memcpy(char *dest, char *src, unsigned int n) {
	char *d = dest;
	char *s = src;
	while (n--) {
		*d++ = *s++;
	}
	return dest;
}
