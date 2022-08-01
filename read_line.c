#define READ_LINE_BUFSIZE 1024
#include "header_shell.h"
/*
 * read_line - Checks if we have a EOF
 * Returns: Buf as the stdin
 */

char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;
	
	if (getline(&buf, &bufsize, stdin) == -1)
	{
		if (feof(stdin)) /*Checking for EOF*/
		{
			exit(EXIT_FAILURE);
		}
		else
		{
		perror("Readline error\n");
		exit(EXIT_FAILURE);
		}
	}

	return buf;
}
