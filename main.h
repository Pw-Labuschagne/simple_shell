#ifndef MAIN_H
#define MAIN_H

#define MAXINPUT 1024

extern char **environ;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char** argv, char** envp);
int cmd_builtins(char* str);

#endif
