/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:46:37 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/17 13:57:51 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*ft_reload(unsigned int nbr, int length, char *str)
{
	while (nbr > 0)
	{
		str[--length] = 48 + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				length;
	unsigned int	m;

	length = ft_len(n);
	str = (char *)malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = '\0';
	if (n < 0)
	{
		m = (unsigned int)(-(n + 1)) + 1;
		str[0] = '-';
	}
	else
		m = (unsigned int)n;
	if (m == 0)
		str[0] = '0';
	else
		ft_reload(m, length, str);
	return (str);
}
