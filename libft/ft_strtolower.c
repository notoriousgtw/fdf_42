/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:10:45 by gwood             #+#    #+#             */
/*   Updated: 2018/03/05 17:04:49 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}
