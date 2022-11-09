#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

/* Clear the shell using escape sequence */
#define clear() printf("\033[H\033[J")

void startup(void);
char * getInput(void);

#endif
