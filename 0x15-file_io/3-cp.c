#include "main.h"

#define PERMISSIONS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)
#define USAGE "Usage: cp file_from file_to\n"
#define ERR_NOREAD "Error: Can't read from file %s\n"
#define ERR_NOWRITE "Error: Can't write to %s\n"
#define ERR_NOCLOSE "Error: Can't close fd %d\n"

/**
 * handle_error - function that prints an error message and
 *			exit with an error code
 * @msg: it's pointer to the error message to be displayed
 * @arg1: it's the argument to be includes in that error message
 * @exit_code: it's the exit code to be used when exiting the program
 *
 * Return: void
 */
void handle_error(const char *msg, const char *arg1, int exit_code)
{
	fprintf(stderr, msg, arg1);
	exit(exit_code);
}

/**
 * open_file_from - Open a source file
 * @src_file: it's pointer to the source file to be opened
 *
 * Return: src_fd, the file descriptor of that opened source file
 */
int open_file_from(const char *src_file)
{
	int src_fd;

	src_fd = open(src_file, O_RDONLY);
	if (src_fd == -1)
	{
		handle_error(ERR_NOREAD, src_file, 98);
	}

	return (src_fd);
}

/**
 * open_file_to - Open a destination file
 * @dst_file: it's pointer to the destination file to be opened
 *
 * Return: dest_fd, the file descriptor of the opened destination file
 */
int open_file_to(const char *dst_file)
{
	int dest_fd;

	dest_fd = open(dst_file, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	if (dest_fd == -1)
	{
		handle_error(ERR_NOWRITE, dst_file, 99);
	}

	return (dest_fd);
}

/**
 * copy_file - function that copies file contents
 *		from source file_from to destination file_to
 * @src_fd: it's the file descriptor of the source file
 * @dest_fd: it's the file descriptor of the destination file
 *
 * Return: Void
 */
void copy_file(int src_fd, int dest_fd)
{
	ssize_t cp;
	char buff[READ_BUFF_SIZE];

	while ((cp = read(src_fd, buff, READ_BUFF_SIZE)) > 0)
	{
		if (write(dest_fd, buff, cp) != cp)
		{
			handle_error(ERR_NOWRITE, "dest_fd", 99);
		}
	}

	if (cp == -1)
	{
		handle_error(ERR_NOREAD, "src_fd", 98);
	}
}

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

	if (argc != 3)
	{
		handle_error(USAGE, "", 97);
	}

	src_fd = open_file_from(argv[1]);

	dest_fd = open_file_to(argv[2]);

	copy_file(src_fd, dest_fd);

	if (close(src_fd) == -1)
	{
		handle_error(ERR_NOCLOSE, "src_fd", 100);
	}

	if (close(dest_fd) == -1)
	{
		handle_error(ERR_NOCLOSE, "dest_fd", 100);
	}

	if (chmod(argv[2], PERMISSIONS) == -1)
	{
		handle_error("Error: Can't set permissions for %s\n", argv[2], 99);
	}

	return (EXIT_SUCCESS);
}


