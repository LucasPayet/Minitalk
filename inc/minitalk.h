/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:07:17 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/26 14:37:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct	s_client
{
	int		pid;
	char		c;
	int		bits;
	char		*text;
	struct s_client	*next;
}	t_cl;

#endif
