#include "main.h"

#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to file %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"

/**
 * handle_error - Prints an error message and exits with an error code.
 * @msg: The error message format.
 * @arg: The argument to include in the error message.
 * @exit_code: The exit code to use when exiting the program.
 *
 * Return: void
 */
void handle_error(const char *msg, const char *arg, int exit_code)
{
	dprintf(STDERR_FILENO, msg, arg);
	exit(exit_code);
}

/**
 * open_file_from - Opens a source file for reading.
 * @src_file: The path to the source file to be opened.
 *
 * Return: The file descriptor of the opened source file.
 */
int open_file_from(const char *src_file)
{
	int src_fd;

	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
		handle_error(ERR_NOREAD, src_file, 98);

	return (src_fd);
}

/**
 * open_file_to - Opens a destination file for writing.
 * @dst_file: The path to the destination file to be opened.
 *
 * Return: The file descriptor of the opened destination file.
 */
int open_file_to(const char *dst_file)
{
	int dest_fd;

	dest_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (dest_fd == -1)
		handle_error(ERR_NOWRITE, dst_file, 99);

	return (dest_fd);
}

/**
 * copy_file - Copies file contents from source to destination.
 * @src_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 *
 * Return: void
 */
void copy_file(int src_fd, int dest_fd)
{
	ssize_t cp;
	char buff[READ_BUFF_SIZE];

	while ((cp = read(src_fd, buff, READ_BUFF_SIZE)) > 0)
	{
		if (write(dest_fd, buff, cp) != cp)
			handle_error(ERR_NOWRITE, "file", 99);
	}

	if (cp == -1)
		handle_error(ERR_NOREAD, "file", 98);
}

/**
 * main - Entry point, copies the contents of a file to another.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Return: 1 on success, 0 if it fails.
 */
int main(int argc, char **argv)
{
	int src_fd = 0, dest_fd = 0;

	if (argc != 3)
		handle_error(USAGE, "", 97);

	src_fd = open_file_from(argv[1]);
	dest_fd = open_file_to(argv[2]);

	copy_file(src_fd, dest_fd);

	if (close(src_fd) == -1)
		handle_error(ERR_NOCLOSE, "src_fd", 100);

	if (close(dest_fd) == -1)
		handle_error(ERR_NOCLOSE, "dest_fd", 100);

	if (chmod(argv[2], PERMISSIONS) == -1)
		handle_error("Error: Can't set permissions for %s\n", argv[2], 99);

	return (EXIT_SUCCESS);
}

