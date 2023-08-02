#include "shell.h"

int main(void)
{
	char *line, **commands, **path, *path_val;

	size_t n = 0;
	int i;
	pid_t cpid;

	while(1)
	{
		i = 0;
		commands = malloc(30);
		path = malloc(50);
		line = NULL;

		printf("$ ");
		getline(&line, &n, stdin);

		line = strtok(line, "\n");
		path_val = getenv("PATH");

		commands[i] = strtok(line, " ");
		while(commands[i])
		{
			i++;
			commands[i] = strtok(NULL, " ");
		}

		i = 0;
		path[i] = malloc(100);
		path[i] = strtok(path_val, ":");
		while(path[i])
		{
			path[i] = strcat(path[i], "/ls");
			i++;
			path[i] = malloc(100);
			path[i] = strtok(NULL, ":");
		}

		printf("%s\n", path[0]);

		cpid = fork();
		if (cpid == -1)
			return (-1);
		else if (cpid == 0)
		{
			execve(commands[0], commands, NULL);
		}
		else
			wait(NULL);

		free(path);
		free(commands);
		free(line);
	}

	return (_SUCCESS);
}
