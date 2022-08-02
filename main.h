#ifndef MAIN_H
#define MAIN_H

#define MAX_ARGS 128
#define bufsize 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * command - checks if it is builtin commands
 */
struct command {
	int argc;
	char *argv[MAX_ARGS];
	enum builtin_t {
		NONE, QUIT, JOBS, BG, FG } builtin;
};


void init_shell(void);
void loop();
int parse_line(const char *buf, struct command *cmd);
void eval_command(char *buf);
void runSystemCommand(struct command *cmd, int bg);

#endif
