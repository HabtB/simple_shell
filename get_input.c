#include "shell.h"

/**
 * getInput - gets input from a user using getline function
 * Return: On success returns number of characters read
 * On failure returns -1
 */
char *getInput(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}

	return (line);
}
