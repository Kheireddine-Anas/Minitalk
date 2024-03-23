/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:14:24 by akheired          #+#    #+#             */
/*   Updated: 2024/03/23 19:18:57 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_hand(int sig, siginfo_t *fors, void *nothing);
void	snd_msg(int pid, char *msg);
void	show_pid(int n_pid);

int		to_int(char *str);

#endif