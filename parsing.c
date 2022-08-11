#include "main.h"

/**
 * parse_line - Function used to parse the input string
 * @str_in: input string from user(main)
 * Return: character pointer
 */

char** parse_line(char *str_in)
{
	int len = 0;
	int max = 16;
	char **tokens = malloc(max * sizeof(char*));
	char *delim = " \t\r\n";
	char *token = strtok(str_in, delim);

	while (token != NULL)
	{
		tokens[len] = token;
		len ++;

		if (len >= max)
		{
			max = (int)(max * 1.5);
			tokens = realloc(tokens, max * sizeof(char*));
		}

		token = strtok(NULL, delim);
	}

	tokens[len] = NULL;
	return tokens;
}

