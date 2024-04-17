#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX_ARGS 100

/**
 * get_argument - handle command lines with arguments
 * @line: path + argument
 * Return: an array of each element of path
 */

char **get_argument(char *line)
{
	int i = 0;
	char *tmp = malloc(strlen(line) + 1);
	char *token;
	char **array = malloc(sizeof(char *) * MAX_ARGS);

	if (tmp == NULL || array == NULL)
		perror("malloc"), exit(EXIT_FAILURE);
	strcpy(tmp, line);
	token = strtok(line, " \t\r\n\a");
	while (token)
	{
		array[i] = malloc(strlen(token) + 1);
		if (array[i] == NULL)
			perror("malloc"), exit(EXIT_FAILURE);
		strcpy(array[i], token);
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}
	array[i] = NULL;
	free(tmp);
	return (array);
}
