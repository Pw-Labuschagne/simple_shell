#include "main.h"

/**
 * exec_cmd - Will be used to execute a command from the main
 * @args: Arguments fed from main
 * @env: Enviromental variablles
 * Return: nothing
 */

void exec_cmd(char **args, char **env)
{

	if (!cmd_compare(args))
	{
	pid_t child = fork();

	if (child < 0)
	{
		perror("Forking problem!");
	}

	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			printf("Could not execute command!\n");
			exit(0);
	} else if (child > 0)
	{
		int status;

		do {
			waitpid(child, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	} else
	{
		perror("Can't execve!\n");
	}
	}
	}
}
