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
char** parse_line(char *str_in);
void exec_cmd(char **args, char **env);
void cd_something(char **args);
void clear_me();
void exit_me(char **args);
int cmd_compare(char **args);


#endif
