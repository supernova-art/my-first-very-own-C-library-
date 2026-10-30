/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 09:48:57 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/28 11:32:35 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_len(s1);
	s2_len = ft_len(s2);
	string = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}
