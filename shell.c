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

void print_cwd()
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s", cwd);
}
/**
 * get_input - Used to get the user input
 * @str: Input from the user
 * Return: 
 */
int get_input(char* str)
{
	char* buf;
	size_t buf_len = 0;

	printf("($):");
	getline(&buf,&buf_len, stdin);

	if (strlen(buf) != 0)
	{
		strcpy(str, buf);
		return (0);
	}else if (feof(stdin))
	{
		perror("End of file detected!\n");
		exit (1);
	}else{
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
int main(int argc, char **argv, char **envp)
{
	char str_in[MAXINPUT];

      	environ = envp;
	shell_welcome();

	while (1)
	{
		print_cwd();
		get_input(str_in);
		cmd_builtins;

return (0);
}
