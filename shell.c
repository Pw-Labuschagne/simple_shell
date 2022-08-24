#include "main.h"

/**
 * shell_welcome - Just used to welcome the user to the shell
 * Return: Nothing
 */
void shell_welcome(void)
{
	printf("##########################################################\n");
	printf("	Welome to our version of a Simple Shell\n");
	printf("	Creators: PW Labuschagne && Jacques Brophy\n");
	printf("##########################################################\n");
	printf("	We hope you enjoy :D. Let's GO!\n");
	printf("##########################################################\n");

	sleep(3);
	system("clear");
}
/**
 * print_cwd - Prints the working direcory
 * Return: nothing
 */
void print_cwd(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
}
/**
 * get_input - Used to get the user input
 * @str: Input from the user
 * Return: 0 if succesful
 */
int get_input(char *str)
{
	char *buf;
	size_t buflen = 0;

	getline(&buf, &buflen, stdin);

	if (strlen(buf) != 0)
	{
		strcpy(str, buf);
		return (0);
	} else if (feof(stdin))
	{
		perror("End of file detected!");
		SIGKILL;
		exit(0);
	} else
	{
		return (1);
	}
}

/**
 * main - The main of the shell. Used to call functions for shell
 * @argc: Number of inputs
 * @argv: String of inputs
 * @envp: Null terminator
 * Return: 0 On success, 1 on error
 */
int main(char **envp)
{
	char str_in[MAXINPUT];
	char **tokens = malloc(sizeof(char *));
	int inter = 1;
	/*int c;*/

	environ = envp;
	shell_welcome();


	while (inter)
	{
		inter = isatty(STDIN_FILENO);
		if (inter == 1)
		{
			print_cwd();
			printf("($):");
		}
		get_input(str);
		if (execve(/bin/, str, NULL))
		{
			perror("Error");
	}
return (0);
}
/**
 * print_env - used to print enviromental variables
 * @env - Enviroment from main
 * Return: 0 if succesful
 */

int print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}


