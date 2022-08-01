#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM "\t\r\n\a"
#include "header_shell.h"
/**
 * split_line - Time to parse our line of arguments
 * @buf: The input from stdin
 * Return: tokens
 */

char **split_line(char *buf)
{
	int bufsize = TOKEN_BUFSIZE, posi = 0;
	char **tokens = malloc(bufsize * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(buf, TOKEN_DELIM);
	
	while (token != NULL)
	{
		tokens[posi] = token;
		posi++;

		if (posi >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "We have a allocation error");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, TOKEN_DELIM);
	}

	tokens[posi] = NULL;
	return tokens;
}
