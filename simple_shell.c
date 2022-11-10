#include "shell.h"

/**
 * main - entry point of the shell, checks interactivity
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *read;
	char **tokens;

	startup();

	while (1)
	{
		printf(">>>> ");
		read = getInput();
		tokens = parser(read);

		printf("The tokens are: ");

		while (*tokens != NULL)
		{
			printf("%s, ", *tokens);
			*tokens++;
		}
		printf("\n");
	}

	return (0);
}

