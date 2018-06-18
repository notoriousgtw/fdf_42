/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:18:17 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 20:46:00 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*str;
	char			*str_it;
	unsigned int	i;

	i = 0;
	if (!s && !(*f))
		return (NULL);
	if ((str = ft_strnew((size_t)ft_strlen((char *)s))))
	{
		str_it = str;
		while (*s)
			*str_it++ = (*f)(i++, *s++);
	}
	return (str);
}
