#include "main.h"

/**
 * cd_something - Used to cd
 * @args: Input arguments
 * Return: Nothing
 */

void cd_something(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: Missing cd argument!\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("./hsh: cd!");
		}
	}
}


/**
 * exit_me - Used to exit if entered by user
 * @args: Input arguments
 * Return: nothing
 */
void exit_me(char __attribute__((unused)) **args)
{
	exit(0);
}

/**
 * clear_me - Used to clear the screen
 * Return: nothing
 */
void clear_me(void)
{
	system("clear");
}

/**
 * cmd_compare - Used to determine if it is builin func or not
 * @args: Input string
 * Return: 0 if not 1 if is
 */
int cmd_compare(char **args)
{
	char *builtins[3];
	int n_builtin = 0;
	int c;

	builtins[0] = "clear";
	builtins[1] = "exit";
	builtins[2] = "cd";
	for (c = 0; c < n_builtin; c++)
	{
		if (strcmp(args[0], builtins[c]) == 0)
		{
			n_builtin = c + 1;
			break;
		}
	}

	switch (n_builtin)
	{
	case 1:
		clear_me();
		return (1);
	case 2:
		exit_me(args);
		return (1);
	case 3:
		cd_something(args);
		return (1);
	default:
		break;

	}

	return (0);
}
