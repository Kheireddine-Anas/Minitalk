#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pid = fork();
	if(pid == -1)
		return 1;
	if(pid == 0)
	{
		int i = 1;
		while (1)
		{
			printf("Some\n");
			printf("%d>>%d", pid, i);
			i++;
			usleep(500);
		}
	}
	else{
		kill(pid, SIGSTOP);
		int t = 5;
		do{
			printf("Yo:");
			scanf("%d", &t);

			if(t > 0){
				kill(pid, SIGCONT);
				sleep(t);
				kill(pid, SIGSTOP);
			}
		} while (t > 0);
		kill(pid, SIGKILL);
		wait(NULL);
	}
	return 0;
		
}