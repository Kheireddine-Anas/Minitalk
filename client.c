#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int to_int(char *str)
{
	int num;

	num = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + ((*str++) - 48);
	return (num);
}

void	snd_msg(int pid, char *msg)
{
	int	i;

	while (*msg)
	{
		i = 7;
		while (i >= 0)
		{
			if ((*msg >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(1000);
		}
		// printf(" ");
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(write(1, "Improper format!\n", 18));
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		else
			exit(write(1, "PID Format Error\n", 18));
	}
	snd_msg(to_int(argv[1]), argv[2]);
	snd_msg(to_int(argv[1]), "\n");
	return (0);
}