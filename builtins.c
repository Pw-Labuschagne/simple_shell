#include "header_shell.h"


int cd_me();
int exit_me(char **args);
/*int env(char **args);*/


char *builtin_str[] = {
	"cd_me",
	"exit_me",
	/*"env"*/
};

int (*builtin_func[])(char **) = {
	&cd_me,
	&exit_me,
	/*&env*/
};

int num_builtins()
{
	return sizeof(builtin_str) / sizeof(char *);
}

int cd_me(char **args)
{
	if (args[1] == NULL)
	{
		printf("Error, expected argument to complete \"cd\"\n");
	}else{
		if (chdir(args[1]) != 0)
		{
			perror("Can't complete");
		}
	}
return 1;
}

int exit_me(char __attribute__((unused)) **args)
{
	return 0;
}

/*int env(char **args)
{

	if (strcmp(args[0], "env") == 0)
	{
		putenv(*env);
	}

}*/



