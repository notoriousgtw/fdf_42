/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:14:03 by gwood             #+#    #+#             */
/*   Updated: 2018/02/27 16:38:03 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char *s_it;

	if (s == NULL)
		return (NULL);
	while (ft_iswspace((int)*s))
		s++;
	if (*s == 0)
		return (ft_strnew(0));
	s_it = (char *)(s + ft_strlen((char *)s) - 1);
	while (ft_iswspace((int)*s_it))
		s_it--;
	return (ft_strsub(s, 0, s_it - s + 1));
}
