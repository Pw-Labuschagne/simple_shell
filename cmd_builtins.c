#include "main.h"

/**
 * cmd_builtins - used to check builtin commands
 * @str: Input string from main
 * Return: TBD
 */

int cmd_builtins(char* str)
{
	char* builtins[3];
	int num_built;
	
	builtins[0] = "exit";
	builtins[1] = "clear";
	builtins[2] = "cd";
	/*builtins[3] = "env";*/

	for (num_built = 0; num_built < 3; num_built++)
	{
		if (strcmp(str, builtins[num_built]) == 10)
		{
			num_built++;
			switch(num_built)
			{
				case 1:
					printf("Thanks for using our shell. Goodbye\n");
					exit (0);
				case 2:
					system("clear");
					return (1);
				case 3:
					printf("Still working on the cd command!\n");
					/*chdir(str[1]);*/
					return (1);
				default:
					break;
			}
		}
	}

	return (0);
}
