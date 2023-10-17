#include "main.h"

char *_strpbrk(char *s, char *accept) {
	int i = 0;
	while (*s) {
		for (i = 0; accept[i]; i++) {
			if (*s == accept[i]) {
				return s;
			}
		}
		s++;
	}
	return NULL;
}
