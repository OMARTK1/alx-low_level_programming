#ifndef MAIN_H
#define MAIN_H

#define READ_BUFF_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);
void handle_error(const char *msg, const char *arg1, int exit_code);
int open_file_from(const char *src_file);
int open_file_to(const char *dst_file);
void copy_file(int src_fd, int dest_fd);

#endif
