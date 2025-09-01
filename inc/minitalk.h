/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:17 by lupayet           #+#    #+#             */
/*   Updated: 2025/09/01 14:09:34 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_client
{
	int				pid;
	char			c;
	int				bits;
	char			*msg;
	int				size;
	struct s_client	*next;
}	t_cl;

t_cl	*new_clt(pid_t pid);
int		msg_cat(t_cl *clt);

#endif
