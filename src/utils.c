/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:09:41 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/02 11:38:37 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"
/*
t_cl	*new_clt(pid_t pid)
{
	t_cl	*new;

	new = ft_calloc(sizeof(t_cl), 1);
	new->pid = pid;
	new->msg = ft_calloc(sizeof(char), 100);
	new->size = 100;
	return (new);
}

void	rm_clt(t_cl *head, int pid)
{
	t_cl	*prev;
	t_cl	*next;

	prev = head;
	next = head->next;
	if (curr->pid == pid)
	{
		free(head->msg);
		free(head);
		head = next;
		return ;
	}
	curr = curr->next;
	while (curr)
	{
		next = curr->next;
		next = curr->next;
		if (curr->pid == pid)
		{
			free(curr->msg);
			free(curr);
			prev->next = next;
			return ;
		}
		curr = next;
	}
} */

void	*ft_realloc(void *ptr, size_t new_size, int size)
{
	void	*cp;

	cp = ft_calloc(sizeof(char), new_size);
	if (!cp)
		return (NULL);
	ft_memcpy(cp, ptr, size);
	free(ptr);
	ptr = cp;
	return (ptr);
}

int	strccat(char *dst, const char c)
{
	int	len_dest;

	len_dest = ft_strlen(dst);
	dst[len_dest] = c;
	dst[len_dest + 1] = '\0';
	return (len_dest + 1);
}

int	msg_cat(t_cl *clt)
{
	int	len;

	len = ft_strlen(clt->msg);
	if (len >= clt->size - 1)
	{
		if (!ft_realloc(clt->msg, clt->size + 100, clt->size))
			return (0);
		else
			clt->size += 100;
	}
	strccat(clt->msg, clt->c);
	return (1);
}
