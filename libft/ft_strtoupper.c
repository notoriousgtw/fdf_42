/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:00:31 by gwood             #+#    #+#             */
/*   Updated: 2018/03/05 17:05:27 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	return (str);
}
