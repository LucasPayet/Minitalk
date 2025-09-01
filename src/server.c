/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:17 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/26 14:37:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
#include <unistd.h>
#include <signal.h>

void sig_handler(int signal, siginfo_t *info, void *context)
{
	static t_msg	*list = NULL;
	t_cl		*clt;

	if (!list)
		creat_cl(info.si_pid);
	while (clt)
	{
		if (clt->pid != info->si_pid)
			clt = clt->next;
		else
			break ;
	}
	clt <<= 1;
	if (signal == SIGUSR1)
		clt |= 1;

	clt->bits++;
	if (clt->bits == 8)
	{
		ft_strlcat(clt->msg, &c, 1);
		clt->bits = 0;
		clt->c = 0;
	}
}

void	set_signal_action(void)
{
	struct sigaction	act;

	act.sa_handler = &sig_handler;
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
