#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

void _prompt(void);
size_t read_input(char **line, size_t *len);
void remove_newline(char *str);
void execute_command(char *command);
char *_path(char *line);
char **get_argument(char *line);
char *_env(const char *name);

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#endif
