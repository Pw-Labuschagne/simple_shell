#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char **str = av;
	//int i = 0;
	while (*str != NULL)
	{
		printf("%s\n",*str++);
	}
return (0);
}
