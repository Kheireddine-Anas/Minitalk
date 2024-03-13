#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	hundler(int signum)
{
	if (signum == SIGUSR1)
		printf("MM%d", signum);
	else
		printf("LK%d", signum);
}

void	show_num(int num)
{
	if (num > 9)
		show_num(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

int	main(void)
{
	int pid;

	pid = getpid();
	write(1, "PID : ", 7);
	show_num(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, hundler);
	signal(SIGUSR2, hundler);
	printf("d");
	pause();
	
}