#include "shell.h"
#include <stdio.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	size_t read;

	while (1)
	{
		pid_t pid;

		_prompt();
		read = read_input(&line, &len);

		if (read == 0)
		{
			printf("\n");
			break;
		}

		remove_newline(line);

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			free(line);
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			execute_command(line);
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
