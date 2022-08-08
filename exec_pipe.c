#include "main.h"

/**
 * exec_pipe - This is where all the pipes of our shell wil be executed
 * @parsed: Input from our parsed_str
 * @parsed_pipe: Input from our parsed_pipe
 * Return: Nothing
 */

void exec_pipe(char** parsed, char** parsed_pipe)
{
	int fd[2];/*File descriptors. 0 for reading, 1 for writing*/
	pid_t child_1, child_2;

	if (pipe(fd) < 0)
	{
		perror("Pipe could not really be initialized!\n");
		return;
	}

	child_1 = fork();
	/*Checking if forking worked*/
	if (child_1 < 0)
	{
		perror("Could not fork!\n");
		return;
	}
	/*Forking worked, start executing child_1*/
	if (child_1 == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		
		/*Checking if command 1 exists*/
		if (execve(parsed[0], parsed, NULL) < 0)
		{
			perror("Could not execute command number 1!\n");
			exit(0);
		}
	}else{
		child_2 = fork();

		/*Checking if child_2 could fork*/
		if (child_2 < 0)
		{
			perror("Could not fork!\n");
			return;
		}

		/*Forking success, start executing child_2*/
		if (child_2 == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			
			/*Cheking if command 2 exists*/
			if (execvp(parsed_pipe[0], parsed_pipe) < 0)
			{
				perror("Could not execute command number 2!\n");
				exit(0);
			}
		}
		/*Now it's just waiting time for parent.
		 *Like children coming home from school xD*/
		else{
			wait(NULL);
			wait(NULL);
		}
	}
}








	









