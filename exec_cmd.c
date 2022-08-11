#include "main.h"

/**
 * exec_cmd - Will be used to execute a command from the main
 * @args: Arguments fed from main
 * @env: Enviromental variablles
 * Return: nothing
 */

void exec_cmd(char **args, char **env)
{


	if (cmd_compare(args) != 1)
	{
	pid_t child = fork();

	if (child == 0)
	{
		execve(args[0], args, env);
		perror("Forking problem!\n");
		exit(1);
	}else if (child > 0)
	{
		int status;

		do{
			waitpid(child, &status, WUNTRACED);
		}while(!WIFEXITED(status) && !WIFSIGNALED(status));
	}else{
		perror("Can't execve!\n");
	}
}
}
