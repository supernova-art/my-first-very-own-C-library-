/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-elm <yait-elm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 13:07:38 by yait-elm          #+#    #+#             */
/*   Updated: 2026/10/28 11:23:24 by yait-elm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < size)
	{
		str[i] = (char)c;
		i++;
	}
	return (s);
}
/*
int main(void)
{
    int a = 1337;
    char *p = (char *)&a;
    ft_memset(p + 0, 199, 1);
    ft_memset(p + 1, 250, 1);
    ft_memset(p + 2, 255, 1);
    ft_memset(p + 3, 255, 1);
    printf("%d\n", a);
}*/
