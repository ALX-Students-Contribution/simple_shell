#include "shell.h"

int main(void)
{
	char *line, *commands[10];
	size_t n = 0;

	while(1)
	{
		line = NULL;
		printf("$ ");
		getline(&line, &n, stdin);

		commands[0] = line;
		commands[1] = NULL;

		execve(line, commands, NULL);

		free(line);
	}

	return (_SUCCESS);
}
