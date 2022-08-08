#include "main.h"

/**
 * parse_space - Used to parse all the command words
 * @str: input str from parse_str(main(get_input))
 * @parsed: Arguments from parse_str(parse_pipe)
 * Return: nothing
 */

void parse_space(char* str, char** parsed)
{
	int c;

	for (c = 0; c < MAX_TOKEN; c++)
	{
		parsed[c] = strsep(&str, " ");

		if (parsed[c] == NULL)
		{
			break;
		}
		if (strlen(parsed[c]) == 0)
		{
			c--;
		}
	}
}
/**
 * parse_pipe - Function  to check if our input string has pipes
 * @str: Input string
 * @clean: array
 * Return: 0 if no pipes were found, 1 if there was a pipe detected
 */
int parse_pipe(char* str, char** clean)
{
        int c;

        for (c = 0; c < 2; c++)
        {
                clean[c] = strsep(&str, "|"); /*| is used for pipes*/

                if (clean[c] == NULL)
                {
                        break;
                }
        }

        if (clean[c] == NULL)
        {
                return (0); /*No pipes were detected*/
        }else{
                return (1); /*A pipe was detected*/
        }
}

/**
 * parse_str - Used to parse str input from user with arguments
 * @str: input str fomr user(main)
 * @parsed: Arguments passed by main
 * @parsed_pipe: Pipe arguments passed by main
 * Return: 0 if it is an builtin command, 1 if it is a system command and
 *		2 if it includes a pipe
 */

int parse_str(char* str, char** parsed, char** parsed_pipe)
{
	char* clean[2];
	int pipe = 0;

	pipe = parse_pipe(str, clean);

	if (pipe)
	{
		parse_space(clean[0], parsed);
		parse_space(clean[1], parsed_pipe);
	}else{
		parse_space(str, parsed);
	}

	if (cmd_checks(parsed))
	{
		return (0);
	}else
	{
		return 1 + pipe;
	}
}
