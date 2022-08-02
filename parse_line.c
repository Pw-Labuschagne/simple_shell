#include "main.h"

/**
 * parse_line - It is used to parse the commands fed by buf
 * @buf: Input fed from main.c
 * @cmd: Checks if it allignes in struct
 * Return: 0 on success
 */
int parse_line(const char *buf, struct command *cmd)
{
	static char arr[1024]; /*Copy of command line*/
	const char delim[10] = " \t\r\n"; /*Argument deliminators*/
	char *line = arr; /*Pointer line to traverse the command line*/
	char *token; /*Pointer to end of current argument*/
	char *end_line; /*Pointer to end of buf string*/
	int is_bg; /*Is it a bacground job*/

	if (buf == NULL)
	{
		perror("The command line is NULL\n");
	}
	
	(void) strcpy(line, buf);
	end_line = line + strlen(line);

	cmd->argc = 0; /*Start of the argv list to build*/

	while (line < end_line)
	{
		line += strspn(line, delim);
		if (line >= end_line)
			break;
		/*Skips delimiters*/

		token = line + strcspn(line, delim);
		/*Find token delimiter*/

		*token = '\0';
		/*terminate the token*/

		cmd->argv[cmd->argc++] = line;
		/*Record the token as an argument*/

		if (cmd->argc >= MAX_ARGS -1)
			break;
		/*Just to check if the argv is full*/

		line = token + 1;
	}

	cmd->argv[cmd->argc] = NULL;
	/*Ending the argument list with a NULL pointer*/

	if (cmd->argc == 0)
		return (1);

	cmd->builtin = parseBuiltin(cmd);

	if ((is_bg = (*cmd->argv[cmd->argc -1] == '&')) != 0)
	{
		cmd->argv[--cmd->argc] = NULL;
	/*Once again, should the job run in the background?*/
	/*& means its running in the background*/
	}
return is_bg;
}









