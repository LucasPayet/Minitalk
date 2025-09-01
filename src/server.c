/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:17 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/01 15:22:32 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static t_cl	*list = NULL;
	t_cl		*clt;

	(void)context;
	if (!list)
		list = new_clt(info->si_pid);
	clt = list;
	while (clt)
	{
		if (clt->pid != info->si_pid)
			clt = clt->next;
		else if (!clt->next)
		{
			clt->next = new_clt(info->si_pid);
			clt = clt->next;
			break ;
		}
		else
			break ;
	}
	clt->c <<= 1;
	if (signal == SIGUSR1)
		clt->c |= 1;
	clt->bits++;
	if (clt->bits == 8)
	{
		write(1, &clt->c, 1);
		msg_cat(clt);
		if (clt->c == 0)
			write(1, clt->msg, ft_strlen(clt->msg));
		clt->bits = 0;
		clt->c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	set_signal_action(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}

int	main(void)
{
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	set_signal_action();
	while (1)
		continue ;
	return (0);
}
