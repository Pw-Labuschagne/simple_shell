#include "header_shell.h"

/**
 * init_shell - Welcomes the user to our self created shell for a good user
 * experience
 * Return: Nothing
 */

void init_start_shell() __attribute__((constructor));

void init_start_shell()
{
	int c;
	system("clear");
	printf("Welcome to PW Labuschagne & Jacques Brophy's Simple Shell\n\n\n");
	printf("Be warned use this shell system with caution and at own risk\n");
	
	wait(&c);
	sleep(3);


}

/**
 * the_loop - Loops for user input and execution
 * Returns: Nothing
 */

void the_loop(char **s)
{
char *buf;
char **args = s;
int status;

do{
	printf("($)");
	buf = read_line();
	args = split_line(buf);
	status = execute_line(args);

	free(buf);
	free(args);

}while (status);

}


	
/**
 * shell_input - It takes a user input
 * Return: 0 on success
 */

int main(int __attribute__((unused)) argc, char **argv)
{


the_loop(argv);


return (0);
}

