#include "shell.h"

/**
 * main - entry point of the shell, checks interactivity
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	char *read;

	startup();

	while (1)
	{
		printf(">>>> ");
		read = getInput();
		printf("%s", read);
	}

	return (0);
}

