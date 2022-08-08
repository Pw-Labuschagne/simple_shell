#include "main.h"

/**
 * sys_command - Executes all the system commands
 * @parsed:  Input that has been parsed
 * Return: Nothing
 */

void sys_commands(char** parsed)
{
	/*Used to fork a child*/
	pid_t pid = fork();

	if (pid == 1)
	{
		perror("Forking failure!");
		return;
	}else if (pid == 0)
	{
		if (execve(parsed[0], parsed, NULL) < 0)
		{
			perror("Could not execute command!");
		}
		exit (0);
	}else{
		/*Waiting for child to finish with execution command*/
		wait(NULL);
		return;
	}
}


