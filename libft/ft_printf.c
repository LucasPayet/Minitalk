/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:35:20 by lupayet           #+#    #+#             */
/*   Updated: 2025/06/11 11:23:38 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	print_ap(char spec, va_list ap)
{
	int	c;

	c = 0;
	if (spec == 'c')
		c += print_c(va_arg(ap, int));
	else if (spec == 's')
		c += print_s(va_arg(ap, char *));
	else if (spec == 'p')
		c += print_p(va_arg(ap, void *));
	else if (spec == 'd' || spec == 'i')
		c += print_n((long)va_arg(ap, int), 10, "0123456789");
	else if (spec == 'u')
		c += print_n(va_arg(ap, unsigned int), 10, "0123456789");
	else if (spec == 'x')
		c += print_n((long)va_arg(ap, unsigned int), 16, "0123456789abcdef");
	else if (spec == 'X')
		c += print_n((long)va_arg(ap, unsigned int), 16, "0123456789ABCDEF");
	else
		c += write(1, &spec, 1);
	return (c);
}

int	ft_printf(const char *format, ...)
{
	int		c;
	va_list	ap;

	c = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format != '%')
			c += write(1, format, 1);
		else
			c += print_ap(*++format, ap);
		format++;
	}
	va_end(ap);
	return (c);
}
