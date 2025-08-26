/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:33 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/26 14:18:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <signal.h>

void	translator(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}

}

int	main(int ac, char *av[])
{
	int	i;

	if (ac < 3)
		return (1);
	i = 0;
	while (av[2][i])
	{
		translator(ft_atoi(av[1]), av[2][i]);
		i++;
	}
}
