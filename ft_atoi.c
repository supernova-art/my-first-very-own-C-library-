/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:46:36 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/17 09:35:07 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_max_long(void)
{
	return ((long)(~0UL >> 1));
}

static int	over_capacity(int sign)
{
	if (sign == 1)
		return ((int)ft_max_long());
	else
		return ((int)(-ft_max_long() - 1));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	result;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > (ft_max_long() - (str[i] - '0')) / 10)
			return (over_capacity(sign));
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return ((int)(sign * result));
}
