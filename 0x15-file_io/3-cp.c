#include "main.h"

#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"
#define ERR_EXISTS "Error: File %s already exists and lacks read permissions\n"

/**
 * main - Entry point, program copies the contents of a file to another
 * @argc: its the number of arguments
 * @argv: its an array of arguments
 *
 * Return: 1 on success, 0 if it's fails
 */
int main(int argc, char **argv)
{
	int src_fd = 0, dest_fd = 0;
	ssize_t cp;
	char buff[READ_BUFF_SIZE];
	struct stat st;

	if (argc != 3)
		dprintf(STDERR_FILENO, USAGE), exit(97);
	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, argv[1]), exit(98);
	if (stat(argv[2], &st) == 0 && S_ISREG(st.st_mode) &&
						(st.st_mode & S_IRUSR) == 0)
	{
		dprintf(STDERR_FILENO, ERR_EXISTS, argv[2]);
		close(src_fd);
		exit(99);
	}
	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (dest_fd == -1)
		dprintf(STDERR_FILENO, ERR_NOWRITE, argv[2]), exit(99);

	while ((cp = read(src_fd, buff, READ_BUFF_SIZE)) > 0)
		if (write(dest_fd, buff, cp) != cp)
			dprintf(STDERR_FILENO, ERR_NOWRITE, argv[2]), exit(99);
	if (cp == -1)
		dprintf(STDERR_FILENO, ERR_NOREAD, argv[1]), exit(98);

	src_fd = close(src_fd);
	dest_fd = close(dest_fd);
	if (src_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, src_fd), exit(100);

	if (dest_fd)
		dprintf(STDERR_FILENO, ERR_NOCLOSE, dest_fd), exit(100);

	if (chmod(argv[2], PERMISSIONS) == -1)
		dprintf(STDERR_FILENO, "Error: Can't set permissions for %s\n",
				argv[2]), exit(99);

	return (EXIT_SUCCESS);
}
