#include "header_shell.h"
#include "builtins.c"
#include "processes.c"
/**
 * execute_line - Well it executes a line in the terminal
 * @args: The command to be executed
 * Return: Fucntion to be used
 */

int execute_line(char **args)
{
int i;

	if (args[0] == NULL)
	{
		return 1; /*No command was entered*/
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return (builtin_func[i])(args);
		}
	}

	return launch_process(args);
}
