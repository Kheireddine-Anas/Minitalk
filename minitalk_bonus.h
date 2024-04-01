/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheired <akheired@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:41:14 by akheired          #+#    #+#             */
/*   Updated: 2024/04/01 14:41:29 by akheired         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	sig_hand(int sig, siginfo_t *fors, void *nothing);
void	snd_msg(int pid, char *msg);
void	show_pid(int n_pid);

int		to_int(char *str);

#endif