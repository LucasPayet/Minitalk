/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:30:13 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/05 08:16:09 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

t_cl	*new_clt(pid_t pid)
{
	t_cl	*new;

	new = ft_calloc(sizeof(t_cl), 1);
	new->pid = pid;
	new->msg = ft_calloc(sizeof(char), 101);
	new->size = 101;
	return (new);
}

void	free_clt(t_cl *clt)
{
	free(clt->msg);
	free(clt);
}

void	rm_clt(t_cl **head, int pid)
{
	t_cl	*pos[3];

	pos[0] = *head;
	pos[1] = *head;
	pos[2] = pos[0]->next;
	if (pos[0]->pid == pid)
	{
		free_clt(pos[0]);
		*head = pos[2];
		return ;
	}
	pos[0] = pos[0]->next;
	while (pos[0])
	{
		pos[2] = pos[0]->next;
		if (pos[0]->pid == pid)
		{
			free_clt(pos[0]);
			pos[1]->next = pos[2];
			return ;
		}
		pos[1] = pos[0];
		pos[0] = pos[2];
	}
}
//pos[0, 1, 2] = curr, prev, next;
