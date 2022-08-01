#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	char *arr[] = {"/bin/ls", "-l", "/tmp", NULL};
	int status;
	pid_t  my_pid;
	pid_t  child_pid;

	my_pid = getpid();

	printf("Before the execve\n");
	printf("Parent pid = %u\n", my_pid);
	

	for (int x = 0; x < 4; x++)
	{	
		child_pid = fork();
		printf("Child nr %d pid is %u\n", x, child_pid);
		child_pid = getppid();
		printf("Child nr %d parent pid is %u\n",x, child_pid);
	
		if (child_pid == -1)
		{
			perror("something went wrong:D\n");
			return (-1);
		}
		else
		{
			if (execve(arr[x], arr, NULL) == -1)
			{
				printf("SOMETHING WENT WRONG :D");
			}
		}
		if (child_pid == 0)
		{
			sleep(2);
			wait(&status);
		}
		printf("After execve");
	}
	return (0);
}
