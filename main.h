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

int _getline(void);
int main(int argc, char **argv, char **envp);
char **parse_line(char *str_in);
void exec_cmd(char **args, char **env);
void cd_something(char **args);
void clear_me(void);
void exit_me(void);
int cmd_compare(char **args);
int print_env(char **env);

#endif
