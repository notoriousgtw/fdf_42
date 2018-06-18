/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:35:24 by gwood             #+#    #+#             */
/*   Updated: 2018/03/01 15:33:16 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void		*d;
	const void	*s;

	d = dst + len - 1;
	s = src + len - 1;
	if (src > dst)
		return ((void *)ft_memcpy(dst, src, len));
	else
		while (len--)
			*(t_byte *)d-- = *(t_byte *)s--;
	return (dst);
}
