/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:21:22 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 15:33:42 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *save;

	save = dst;
	while (len--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = 0;
	}
	return (save);
}
