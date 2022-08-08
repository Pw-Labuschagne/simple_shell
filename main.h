#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>



#define MAX_TOKEN 256 /*The max ammount of token per command*/
#define MAX_LINE 1024 /*Max character input from user*/

/*static char* cDirectory;*/

void shell_welcome(void);
void init_shell(void);
int main(int argc, char **argv, char **env);
int get_input(char* str);
int parse_str(char* str, char** parsed, char** parsed_pipe);
void parse_space(char* str, char** parsed);
void exec_pipe(char** parsed, char** parsed_pipe);
void sys_commands(char** parsed);
int cmd_checks(char** parsed);
int parsed_pipe(char* str, char** clean);
void parse_space(char* str, char** parsed);


#endif
