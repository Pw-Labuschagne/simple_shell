#include "main.h"

/*Declaration of the constructor init_shell*/
void init_shell(void)__attribute__((constructor));

/**
 * init_shell - Startup of shell for new users
 * Return: Nothing
 */
void init_shell(void)
{
	system("clear");
	printf("#######################################################\n");
	printf("Welcome to the SIMPLE SHELL\n");
	printf("This is our own version of what a simple shell would be\n");
	printf("#######################################################\n");
	printf("Creators : PW Labuschagne && Jacques Brophy\n");
	printf("#######################################################\n");
	printf("		LET\'S START			\n");
	printf("######################################################\n");
	sleep(4);
}

/**
 * loop - The REPL loop for the shell
 * Return: nothing;
 */
void loop()
{
	static int first = 1;
	char *buf;
	size_t buffs = 0;

	if (first)
	{
		system("clear");
		first = 0;
	}
	else
	{
		printf("($)");
	}

	while(1)
	{
		printf("($)");
		if  (getline(&buf, &buffs, stdin) == EOF && ferror(stdin))
		{
			perror("Readline error!");
		}
		if (feof(stdin))
		{
			printf("\n");
			exit(0);
		}

		buf[strlen(buf) -1] = '\0';
		eval_command(buf);

	}


}
/**
 * main - The basis of the shell system
 * @argc: Ammount of commands fed to the shell
 * @argv: The string commands fed to the shell
 * Return: 0 on success
 */
int main(int argc, char **argv)
{


/*REPL loop*/
	loop();



return (0);
}
