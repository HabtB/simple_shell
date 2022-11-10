#ifndef SHELL_H
#define SHELL_H

/**###### MACROS #####*/

#define BUFSIZE 1024;



/**###### LIBRARIES USED #####*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


/* Clear the shell using escape sequence */
#define clear() printf("\033[H\033[J")



/**###### Parser and extractor functions #####*/


void startup(void);
char * getInput(void);
char **parser(char *line);

#endif
