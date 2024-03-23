/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:44:21 by akheired          #+#    #+#             */
/*   Updated: 2024/03/23 17:25:00 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	to_int(char *str)
{
	int	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
		num = num * 10 + ((*str++) - 48);
	return (num);
}

void	done_bck(int pid, char c)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(10);
	}
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
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(90);
		}
		msg++;
	}
	if (*msg == '\0')
		done_bck(pid, *msg);
}

void	done_receive(int sig_rec)
{
	if (sig_rec == SIGUSR2)
		write(1, "MSG HAS BEEN RECEIVED\n", 22);
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
	if (to_int(argv[1]) <= 0)
		exit(write(1, "PID doesn't exist\n", 18));
	signal(SIGUSR2, done_receive);
	snd_msg(to_int(argv[1]), argv[2]);
	return (0);
}
