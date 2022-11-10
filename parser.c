#include "shell.h"
/**
 * parser - parses the line into cmds and arguments
 * @line: is the line given to parse
 *
 * Return: returns the parsed tokens
*/

char **parser(char *line)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (line == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * buffsize);

	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = strtok(line, "\n ");

	i = 0;
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}
