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
	int st = 0, counter = 0;

	startup();

	while (1)
	{
		printf(">>>> ");
		read = getInput();

		if (read[0] == '\0')
		{
			continue;
		}
		history(read);

		tokens = parser(read);

		if (_strcmp(tokens[0], "exit") == 0)
		{
			exit_bul(tokens, read, av, counter);
		}
		else if (check_builtin(tokens) == 0)
		{
			st = handle_builtin(tokens, st);
			free_all(tokens, read);
			continue;
		}
		else
		{
			st = check_cmd(tokens, read, counter, av);

		}
		free_all(tokens, read);
	}
	return (1);
}


/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup(environ[i]);
	envi[i] = NULL;
}
