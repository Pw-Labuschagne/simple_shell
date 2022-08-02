#include "main.h"

/**
 * eval_command - It evaluates the code if it is valid
 * @buf: Command fed to eval function
 * Return: Nothing
 */

void eval_command(char *buf)
{
	int bg;
	struct command cmd;

	bg = parse_line(buf, &cmd);

	if (bg == -1)
	{
		return;
		/*Parsing error*/
	}

	if (cmd.argv[0] == NULL)
	{
		if (cmd.builtin == NONE)
		{
			runSystemCommand(&cmd, bg);
		}else{
			runBuiltinCommand(&cmd, bg);
		}

}
}
