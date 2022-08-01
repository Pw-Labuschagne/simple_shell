#include "header_shell.h"

/**
 * launch_process - This is used to fork and run different preocesses
 * @args: The commands thats needs to be processed
 * Return: exec has no returns, so 1
 */

int launch_process(char **args)
{
	pid_t pid_child, pid_parent; /*Forking our processes*/
	int status; /*Keepint track of our processes*/

	pid_parent = getpid();
	printf("%u\n", pid_parent);
	pid_child = fork();
	if (pid_child == 0) /*The child process*/
	{
			if (execvp(args[0], args) == -1)
			{
				perror("Process error");
				exit(EXIT_FAILURE);/*We ensure to always exit on error*/
			}
			else if (pid_child < 0)
			{
				perror("Proccess error");
			}
			else
			{
				do{
					pid_parent = waitpid(pid_child, &status, WUNTRACED);
				}while (!WIFEXITED(status) && !WIFSIGNALED(status));
			}
	}
return (0);
}
