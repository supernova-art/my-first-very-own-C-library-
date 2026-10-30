/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:48:37 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/21 08:57:30 by yait-elm         ###   ########.fr       */
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

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	total_len;

	i = 0;
	j = 0;
	src_len = ft_len(src);
	while (i < destsize && dest[i])
		i++;
	if (i == destsize)
		return (destsize + src_len);
	total_len = i + src_len;
	while (src[j] && (i + j + 1) < destsize)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (total_len);
}
