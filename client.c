/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:51:00 by akheired          #+#    #+#             */
/*   Updated: 2024/03/29 22:34:09 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	to_int(char *str)
{
	int	num;

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
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(90);
		}
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		exit(write(1, "\033[31mImproper format!\n", 23));
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			i++;
		else
			exit(write(1, "\033[31mPID Format Error\n", 23));
	}
	if (to_int(argv[1]) <= 0)
		exit(write(1, "\033[31mPID doesn't exist\n", 24));
	snd_msg(to_int(argv[1]), argv[2]);
	return (0);
}
