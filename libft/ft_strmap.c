/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:04:49 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 20:45:21 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char *str;
	char *str_it;

	if (!s && !(*f))
		return (NULL);
	if ((str = ft_strnew((size_t)ft_strlen((char *)s))))
	{
		str_it = str;
		while (*s)
			*str_it++ = (*f)(*s++);
	}
	return (str);
}
