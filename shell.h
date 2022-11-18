#ifndef SHELL_H
#define SHELL_H

/**###### MACROS #####*/

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(c) (write(STDOUT_FILENO, c, strlen(c)))

/**###### ENVIRON #####*/

extern char **environ;


/**###### LIBRARIES USED #####*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>



/* Clear the shell using escape sequence */
#define clear() printf("\033[H\033[J")



/**###### Parser and extractor functions #####*/


void startup(void);
char *getInput(void);
char **parser(char *line);
int path_cmd(char **cmd);
char *build(char *token, char *value);
char *_getenv(char *name);
void read_file(char *filename, char **argv);
void treat_file(char *line, int counter, FILE *fp, char **argv);
void exit_bul_for_file(char **cmd, char *line, FILE *fd);
int handle_builtin(char **cmd, int er);
int check_builtin(char **cmd);
int check_cmd(char **token, char *line, int count, char **argv);
void exit_bul(char **cmd, char *input, char **argv, int c);
int change_dir(char **cmd, __attribute__((unused))int er);
int dis_env(char **cmd, int er);
int display_help(char **cmd, __attribute__((unused)) int er);
int echo_bul(char **cmd, int st);
void free_env(char **env);
int history(char *input);
int history_dis(char **cmd, int er);
int print_echo(char **cmd);
void creat_envi(char **envi);
void _prerror(char **argv, int c, char **cmd);
void free_all(char **cmd, char *line);

/**###### Helper functions #####*/


int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);
void _puts(char *str);
char *_strcpy(char *dest, char *src);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_itoa(unsigned int n);
void array_rev(char *arr, int len);
int intlen(int num);
void print_number(unsigned int n);
void print_number_in(int n);
void print_error(char *input, int counter, char **argv);

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

#endif
