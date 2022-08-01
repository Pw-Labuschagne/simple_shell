#ifndef HEADER_SHELL_H
#define HEADER_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stddef.h>

void init_start_shell();
int main();
int execute_line(char **args);
int launch_process(char **args);
char *read_line(void);
char **split_line(char *buf);

#endif
