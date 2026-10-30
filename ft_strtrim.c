/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 13:24:54 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/28 18:05:34 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(const char *set, char pos)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == pos)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(const char *s1, const char *set)
{
	int	start;

	start = 0;
	while (s1[start])
	{
		if (!(ft_is_set(set, s1[start])))
			break ;
		start++;
	}
	return (start);
}

static int	ft_end(const char *s1, const char *set)
{
	int	end;

	end = ft_strlen(s1) - 1;
	while (end >= 0)
	{
		if (!(ft_is_set(set, s1[end])))
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(const char *s1, char const *set)
{
	int	start;
	int	end;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
