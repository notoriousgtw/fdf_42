/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:03:57 by gwood             #+#    #+#             */
/*   Updated: 2018/03/05 16:58:51 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcase(const char *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = ft_tolower(str[i]);
		else
			str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}
