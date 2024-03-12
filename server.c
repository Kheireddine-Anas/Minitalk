#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	hundler(int signum)
{
	if (signum == SIGUSR1)
		printf("LK");
	// if(signum == 1)
	// 	printf("1");
	// else if(signum == 2)
	// 	printf("2");

}

void	show_num(int num)
{
	if (num > 9)
		show_num(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}
void prdf()
{
	printf("tesT");
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
	while (1)
	{
		pause();
	}
	
}