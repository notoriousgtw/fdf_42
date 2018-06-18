/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:01:32 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 20:53:25 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char *str;
	char *str_it;

	if (!s1 || !s2)
		return (NULL);
	if ((str = ft_strnew((size_t)ft_strlen((char *)s1)
					+ (size_t)ft_strlen((char *)s2) + 1)))
	{
		str_it = str;
		while (*s1)
			*str_it++ = *s1++;
		while (*s2)
			*str_it++ = *s2++;
		str_it = 0;
	}
	return (str);
}
