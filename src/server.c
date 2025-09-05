/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:17 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/02 14:11:38 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

t_cl	*g_list;

void	set_bit(int signal, t_cl *clt)
{
	clt->c <<= 1;
	if (signal == SIGUSR1)
		clt->c |= 1;
	clt->bits++;
	if (clt->bits == 8)
	{
		msg_cat(clt);
		if (clt->c == 0)
		{
			write(1, clt->msg, ft_strlen(clt->msg));
			write(1, "\n", 1);
			/*kill(clt->pid, SIGUSR1);
			clt->bits = 0;
			clt->c = 0;
			rm_clt(&g_list, clt->pid);
			return  ;*/
		}
		clt->bits = 0;
		clt->c = 0;
	}
	kill(clt->pid, SIGUSR1);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	t_cl		*clt;

	(void)context;
	if (!g_list)
		g_list = new_clt(info->si_pid);
	clt = g_list;
	while (clt)
	{
		if (clt->pid != info->si_pid)
		{
			if (clt->next)
				clt = clt->next;
			else
			{
				clt->next = new_clt(info->si_pid);
				clt = clt->next;
				break ;
			}
		}
		else
			break ;
	}
	set_bit(signal, clt);
}

void	quit(int signal)
{
	t_cl	*i;

	(void)signal;
	while (g_list)
	{
		i = g_list->next;
		free(g_list->msg);
		free(g_list);
		g_list = i;
	}
	exit(0);
}

void	set_signal_action(void)
{
	struct sigaction	act;
	struct sigaction	qt;

	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	qt.sa_handler = &quit;
	sigemptyset(&qt.sa_mask);
	qt.sa_flags = 0;
	sigaction(SIGINT, &qt, NULL);
	sigaction(SIGTERM, &qt, NULL);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	set_signal_action();
	while (1)
		pause();
	return (0);
}
