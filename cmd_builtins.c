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
void exit_me(void)
{
	printf("Thank you for testing our shell\n");
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
	int n_builtin = 3;
	int c;
	int choose = 0;

	builtins[0] = "clear";
	builtins[1] = "exit";
	builtins[2] = "cd";

	for (c = 0; c < n_builtin; c++)
	{
		if (strcmp(args[0], builtins[c]) == 0)
		{
			choose = c + 1;
			break;
		}
	}
		switch (choose)
		{
				case 1:
					clear_me();
					return (1);
				case 2:
					exit_me();
					return (1);
				case 3:
					cd_something(args);
					return (1);
				default:
					break;
		}
return (0);
}
