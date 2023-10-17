#include "main.h"

unsigned int _strspn(char *s, char *accept) {
	unsigned int count = 0;
	int found = 1;
	while (*s && found) {
		found = 0;
		for (int i = 0; accept[i]; i++) {
			if (*s == accept[i]) {
				count++;
				found = 1;
				break;
			}
		}
		if (found) {
			s++;
		}
	}
	return count;
}
