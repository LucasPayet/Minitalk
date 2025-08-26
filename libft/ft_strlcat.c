/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:45:13 by lupayet           #+#    #+#             */
/*   Updated: 2025/04/28 15:06:36 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	j;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	j = 0;
	if (siz <= len_dest)
		return (len_src + siz);
	while (src[j] && (len_dest + j) < (siz - 1))
	{
		dst[len_dest + j] = src[j];
		j++;
	}
	dst[len_dest + j] = '\0';
	return (len_dest + len_src);
}
