/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 15:17:46 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/16 18:02:11 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && !(s[i] == c))
	{
		i++;
	}
	return (i);
}

static char	**free_string(char **s, int c)
{
	while (c > 0)
	{
		c--;
		free(s[c]);
	}
	free(s);
	return (NULL);
}

static char	*allocation(char const *s, char c, int *i)
{
	char	*word;
	int		len;
	int		j;

	j = 0;
	len = word_len(s + (*i), c);
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (j < len)
		word[j++] = s[(*i)++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	strings = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
		{
			strings[j] = allocation(s, c, &i);
			if (!strings[j])
				return (free_string(strings, j));
			j++;
		}
	}
	strings[j] = 0;
	return (strings);
}
