#include "main.h"

/**
 * init_shell - Used to welcome user to newly designed shell.
 * Return: Nothing
 */

void init_shell()__attribute__((constructor));
/*Used to start-up before the main function*/

void init_shell()
{
	system("clear");
	printf("Welcome to PW Labuschange &&");
	printf(" Jacques Brophy's desgin of a simple shell\n");
	printf("-------------------------------------");
	printf("---------------------------------\n");
	printf("BE WARNED: Use this shell at own risk!\n");
	printf("-------------------------------------");
	printf("---------------------------------\n");
	sleep(3);
	system("clear");
}

/**
 * main - This is our version of a simple shell
 * @ac: number of arguments fed to shell
 * @av: String fed to program
 * @env: Enviroment
 * Return: Result of the command
 */

int main(int ac, char **av, char __attribute__((unused))**env)
/*Used to get the user input to shell*/
{
	char *buf;
	size_t bufsize = 0;

	while (1)
	{
	printf("($)");
		if ((getline(&buf, &bufsize, stdin) == -1))
		{
			if (feof(stdin))
			{
				exit(EXIT_FAILURE);
			}
			else
			{
				perror("Readline");
			}
		}
	}


return (0);
}
