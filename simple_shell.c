#include "shell.h"

/**
 * main - entry point of the shell, checks interactivity
 * @ac: arg count
 * @av: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char *av[])
{
	char *read;
	char **tokens;
	int i;

	startup();

	while (1)
	{
		printf(">>>> ");
		read = getInput();
		tokens = parser(read);

		printf("The tokens are: ");

		i = 0;
		while (tokens[i] != NULL)
		{
			printf("%s, ", tokens[i]);
			i++;
		}
		printf("\n");
	}

	return (0);
}
