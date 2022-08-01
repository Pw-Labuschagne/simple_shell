#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *buf;
	size_t bufsize = 32;

	buf = malloc(sizeof(bufsize * sizeof(char)));

	if (buf == NULL)
	{
		perror("Unable to allocate the buffer!\n");
		exit(-1);
	}

	printf("$ ");
	getline(&buf, &bufsize, stdin);
	printf("%s", buf);

	return (0);

}
