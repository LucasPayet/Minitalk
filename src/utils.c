/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:41 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/01 14:14:33 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

t_cl	*new_clt(pid_t pid)
{
	t_cl	*new;

	new = ft_calloc(sizeof(t_cl), 1);
	new->pid = pid;
	new->msg = ft_calloc(sizeof(char), 100);
	return (new);
}

void	*ft_realloc(void *ptr, size_t new_size, int size)
{
	void	*cp;
	cp = ft_calloc(sizeof(char), new_size);
	if (!cp)
		return (NULL);
	if (ft_memcpy(cp, ptr, size))
	{
		free(ptr);
		ptr = cp;
	}
	else
	{
		free(cp);
		return (NULL);
	}
	return (ptr);
}

int	msg_cat(t_cl *clt)
{
	int	len;

	len = ft_strlen(clt->msg);
	if (len >= clt->size - 1)
		if (!ft_realloc(clt->msg, clt->size + 100, clt->size))
			return (0);
	ft_strlcat(clt->msg, &clt->c, 1);
	return (1);
}
