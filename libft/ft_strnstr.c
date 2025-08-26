/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:49:12 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/05 11:16:00 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l_len;
	size_t	i;

	if (!(*little))
		return ((char *)big);
	l_len = ft_strlen(little);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len - l_len + 1)
	{
		if (!ft_strncmp(&big[i], little, l_len))
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
