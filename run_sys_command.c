#include "main.h"

/**
 * runSystemCommand - Running our command
 * @cmd: Struct where the builtins lie
 * @bg: Background proccess
 * Return: Nothing
 */
void runSystemCommand(struct command *cmd, int bg)
{
	pid_t child_pid;
	/*This is where we fork the command*/

	if ((child_pid = fork()) < 0)
	{
		perror("Error with forking");
	}else if (child_pid == 0)
	/*Child running the command*/
	{	if (execvp(cmd->argv[0], cmd->argv) < 0)
			{
				/*Where we are using our execpv (execute)*/
				printf("%s: Command not found!\n", cmd->argv[0]);
				exit(0);
			}
	}
	else{
	/*This is the parent process, waiting on child proccess*/
		if (bg)
			{
				printf("Child proccess running in");
			      	printf(" background [%d}\n", child_pid);
			}else{
				wait(&child_pid);
			}
	}
}

