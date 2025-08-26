/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:04:51 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/02 17:00:07 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nblen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*nb;
	size_t	len;

	nbr = n;
	len = ft_nblen(nbr);
	nb = (char *)malloc(len + 1);
	if (!nb)
		return (NULL);
	if (nbr < 0)
	{
		*nb = '-';
		nbr = -nbr;
	}
	nb[len] = '\0';
	len--;
	if (nbr == 0)
		nb[len] = '0';
	while (nbr)
	{
		nb[len--] = (nbr % 10 + 48);
		nbr /= 10;
	}
	return (nb);
}
