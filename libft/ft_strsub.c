/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 10:43:43 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 20:53:15 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char *str;
	char *str_it;

	if (!s)
		return (NULL);
	if ((str = ft_strnew(len)))
	{
		str_it = str;
		while (start--)
			s++;
		while (len--)
			*str_it++ = *s++;
	}
	return (str);
}
