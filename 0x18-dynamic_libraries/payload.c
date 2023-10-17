#define _GNU_SOURCE
#include <stdlib.h>

void __attribute__((constructor)) set_numbers(void) {
    setenv("WINNING_NUMBERS", "9 8 10 24 75 9", 1);
}
