/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:33 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/01 15:23:55 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <signal.h>

int	p;

void	update_stop(int	signal)
{
	(void)signal;
	p = 0;
}

void	set_signal_action(void)
{
	struct sigaction	act;

	sigemptyset(&act.sa_mask);
	act.sa_handler = &update_stop;
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
}

void	translator(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		p = 1;
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while (p);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	spid;

	if (ac < 3)
		return (1);
	i = 0;
	set_signal_action();
	spid = ft_atoi(av[1]);
	while (av[2][i])
	{
		translator(spid, av[2][i]);
		i++;
	}
	translator(spid, '\0');
}
