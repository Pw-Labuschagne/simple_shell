#include "main.h"

/**
 * cmd_checks - Now this is used to check if our input is builtin
 * 		and if so, to execute them...fun.
 * @parsed: Parsed string passed from our parsed_str to execute builtin
 * Return: 1 if command is executed, 0 if none was found.
 */

int cmd_checks(char** parsed)
{
	int num_builtins = 3/*Continue once env and alias is configured,
			      change to 5*/, c, switch_func = 0;
	char* builtins_list[3];
	
	builtins_list[0] = "exit";
	builtins_list[1] = "cd";
	builtins_list[2] = "clear";
	/*to be updated with env and alias, change to 5*/
	/*env builtin needed*/

	for (c = 0; c < num_builtins; c++)
	{
		if (strcmp(parsed[0], builtins_list[c]) == 0)
		{
			switch_func = c + 1;
			break;
		}
	}

	switch (switch_func){
		case 1: 
			printf("Exit command detected.");
		        printf("Thanks for using our shell\n");
			exit (0);
		case 2:
			chdir(parsed[1]);
			return (1);
		case 3:
			system("clear");
		default:
			break;
	}
	return (0);
}


