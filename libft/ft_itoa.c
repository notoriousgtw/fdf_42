/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:33:49 by gwood             #+#    #+#             */
/*   Updated: 2018/03/17 21:01:49 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	neg(long *n, int *negative, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		*i += 1;
	}
}

char		*ft_itoa(int n)
{
	long	num;
	int		i;
	char	*str;
	long	tmp;
	int		negative;

	i = 2;
	negative = 0;
	num = (long)n;
	tmp = num;
	while (tmp /= 10)
		i++;
	neg(&num, &negative, &i);
	if (!(str = ft_memalloc(i--)))
		return (NULL);
	while (i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
