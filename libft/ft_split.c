/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:17:54 by lupayet           #+#    #+#             */
/*   Updated: 2025/05/07 13:25:55 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (*str != c && *str != '\0' && c != '\0')
		count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_list(char **plist)
{
	size_t	i;

	i = 0;
	while (plist[i])
	{
		free(plist[i]);
		i++;
	}
	free(plist);
	return (NULL);
}

static char	**ft_splitw(char const	*s, char c, char **list)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == c)
			temp = i + 1;
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
		{
			list[j] = ft_substr(s, temp, (i + 1 - temp));
			if (!list[j])
			{
				return (ft_free_list(list));
			}
			j++;
		}
		i++;
	}
	list[j] = NULL;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**list;

	words = count_word(s, c);
	list = (char **)malloc((words + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	return (ft_splitw(s, c, list));
}
