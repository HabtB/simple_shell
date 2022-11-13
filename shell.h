#ifndef SHELL_H
#define SHELL_H

/**###### MACROS #####*/

#define BUFSIZE 1024
#define clear() printf("\033[H\033[J")


/**###### LIBRARIES USED #####*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


/**###### Parser and extractor functions #####*/

void startup(void);

#endif
