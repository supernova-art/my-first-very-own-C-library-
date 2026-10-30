/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:37:27 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/22 15:52:35 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	len;

	if (nmemb != 0 && size > (size_t)-1 / nmemb)
		return (NULL);
	len = nmemb * size;
	if (len == 0)
		len = 1;
	s = malloc(len);
	if (!s)
		return (NULL);
	ft_bzero(s, len);
	return (s);
}
