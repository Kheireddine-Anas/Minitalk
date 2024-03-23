/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:44:01 by akheired          #+#    #+#             */
/*   Updated: 2024/03/23 17:16:13 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

int	g_bit_count = 7;

void	show_char(char *c, int client_pid)
{
	(void)client_pid;
	if (!*c)
		kill(client_pid, SIGUSR2);
	write(1, c, 1);
	g_bit_count = 7;
	*c = 0;
}

void	show_pid(int n_pid)
{
	if (n_pid > 9)
		show_pid(n_pid / 10);
	write(1, &"0123456789"[n_pid % 10], 1);
}

void	sig_hand(int sig, siginfo_t *fors, void *nothing)
{
	static int	client_pid;
	static int	recent_process;
	static char	ch_ar;

	client_pid = fors->si_pid;
	if (client_pid != recent_process)
	{
		g_bit_count = 7;
		ch_ar = 0;
		recent_process = client_pid;
	}
	if (sig == SIGUSR2)
	{
		ch_ar |= (1 << g_bit_count);
		g_bit_count--;
	}
	else if (sig == SIGUSR1)
		g_bit_count--;
	if (g_bit_count == -1)
		show_char(&ch_ar, client_pid);
	(void)nothing;
}

int	main(void)
{
	struct sigaction	sigs;

	show_pid(getpid());
	sigs.sa_sigaction = sig_hand;
	sigs.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigs, NULL);
	sigaction(SIGUSR2, &sigs, NULL);
	while (1)
		pause();
	return (0);
}
