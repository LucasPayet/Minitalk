/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:30:13 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/02 11:42:59 by lupayet          ###   ########.fr       */
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
	new->size = 100;
	return (new);
}

void	free_clt(t_cl *clt)
{
	free(clt->msg);
	free(clt);
}

void	rm_clt(t_cl **head, int pid)
{
	t_cl	*curr;
	t_cl	*prev;
	t_cl	*next;

	curr = *head;
	prev = *head;
	next = curr->next;
	if (curr->pid == pid)
	{
		free_clt(curr);
		*head = next;
		return ;
	}
	curr = curr->next;
	while (curr)
	{
		next = curr->next;
		if (curr->pid == pid)
		{
			free_clt(curr);
			prev->next = next;
			return ;
		}
		curr = next;
	}
}
