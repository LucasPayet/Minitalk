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
#include <unistd.h>
#include <signal.h>

void sig_handler(int signal)
{
	static char	c = 0;
	static int	i = 0;

	c <<= 1;
	if (signal == SIGUSR1)
		c |= 1;

	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
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
