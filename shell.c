#include "main.h"

pid_t shell_pgid;
struct termios shell_tmodes;
int terminal;
int interactive;
extern char **environ;

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
 * init_shell - Used to initialize the shell
 * Return: Nothing
 */
void init_shell(void)
{
	/*Are we currently running interactively?*/
	terminal = STDIN_FILENO;
	interactive = isatty (terminal);
	shell_pgid = getpid();	

	if (interactive)
	{
		/*We shall now attempt to loop until we are in the foreground*/
		while (tcgetpgrp (terminal) != (shell_pgid = getpgrp()))
		{
			kill (shell_pgid, SIGTTIN);

		/*Ignore interactive and job signals*/
		signal (SIGINT, SIG_IGN);
		signal (SIGQUIT, SIG_IGN);
		signal (SIGTSTP, SIG_IGN);
		signal (SIGTTIN, SIG_IGN);
		signal (SIGTTOU, SIG_IGN);
		signal (SIGCHLD, SIG_IGN);

		/*Put ourselfs in our own process group*/
		shell_pgid = getpid();

		if (setpgid (shell_pgid, shell_pgid) < 0)
		{
			perror("Error occured trying to put the shell in its own process group\n");
			exit(1);
		}

		/*Attempt to grab control of the terminal*/
		tcsetpgrp (terminal, shell_pgid);

		/*Save the terminal default attributes for the shell*/
		tcgetattr (terminal, &shell_tmodes);

		/*Setting up the current direcory*/
		/*cDirectory = (char*) calloc(1024, sizeof(char));*/
		
		}
	}
}




/**
 * main - The main of the shell. Used to call functions for shell
 * @argc: Number of inputs
 * @argv: String of inputs
 * @envp: Null terminator
 * Return: 0 On success, 1 on error
 */
int main(int argc, char **argv,char **envp)
{
	char input_str[MAX_LINE], *parsed_args[MAX_TOKEN];
	char* args_pipe[MAX_TOKEN];
	int execFlag = 0;

      	environ = envp;

	shell_welcome();
	init_shell();
		
	while (1)
	{
		print_cwd();

		if (get_input(input_str))
			continue;
		execFlag = parse_str(input_str, parsed_args, args_pipe);

		if (execFlag == 1)
			sys_commands(parsed_args);

		if (execFlag == 2)
			exec_pipe(parsed_args, args_pipe);
	}

	return (0);
}

