/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:49:35 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/16 21:55:18 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (print_s("(null)"));
	while (*s)
	{
		write(1, s++, 1);
		c++;
	}
	return (c);
}

int	print_p(void *p)
{
	if (!p)
		return (print_s("(nil)"));
	return (print_s("0x") + print_np((uintptr_t)p));
}

int	print_np(uintptr_t n)
{
	int		c;
	char	*basec;

	c = 0;
	basec = "0123456789abcdef";
	if (n < 16)
		return (write(1, &basec[n], 1));
	else
	{
		c += print_np(n / 16);
		return (c + print_np(n % 16));
	}
}

int	print_n(long n, int base, char *basec)
{
	int	c;

	c = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_n(-n, base, basec) + 1);
	}
	if (n < base)
		return (write(1, &basec[n], 1));
	else
	{
		c += print_n(n / base, base, basec);
		return (c + print_n(n % base, base, basec));
	}
}
