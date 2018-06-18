/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 23:56:43 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 15:41:36 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(t_byte *)dst++ = *(t_byte *)src;
		if (*(t_byte *)src++ == (t_byte)c)
			return ((t_byte *)dst);
	}
	return (NULL);
}
