/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:32:43 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/01 15:11:58 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	char	*j;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	j = (char *)malloc(l_s1 + l_s2 + 1);
	if (!j)
		return (NULL);
	ft_strlcpy(j, s1, l_s1 + 1);
	ft_strlcpy(&j[l_s1], s2, l_s2 + 1);
	return (j);
}
