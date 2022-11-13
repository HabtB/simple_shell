#include "shell.h"

/**
 * main - entry point of the shell, checks interactivity
 * @argc: arg count
 * @argv: array of arguments
 *
 * Return: 0 on success or other integer
 */
int main(int argc, char *argv[])
{
	ssize_t reads;
	char *str = NULL;
	size_t n = 0;


	startup();

	/* declaring void variables */
	(void)argc, (void)argv;
	
	/* create an infinite loop */
	while (1)
	{
		printf("$ ");

		reads = getline(&str, &n, stdin);

		if (reads == -1)
		{
			return (-1);
		}
		printf("%s", str);
	}
	
	/* free allocate memory */
	free(str);

	return (0);
}

