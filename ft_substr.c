/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:36:36 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/15 13:09:48 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	s_len;
	size_t	finito;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	finito = 0;
	if (start < s_len)
		finito = s_len - start;
	if (finito > len)
		finito = len;
	string = (char *)malloc((finito + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (finito == 0)
		string[0] = '\0';
	else
		ft_strlcpy(string, s + start, finito + 1);
	return (string);
}
