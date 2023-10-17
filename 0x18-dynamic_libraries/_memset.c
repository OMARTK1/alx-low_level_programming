#include "main.h"

char *_memset(char *s, char b, unsigned int n) {
	unsigned char *ptr = (unsigned char *)s;
	while (n--) {
		*ptr++ = (unsigned char)b;
	}
	return s;
}
