/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:29:29 by gwood             #+#    #+#             */
/*   Updated: 2018/02/26 15:06:25 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *haystack_it;
	const char *needle_it;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		haystack_it = haystack;
		needle_it = needle;
		while (*needle_it != '\0' && *haystack_it == *needle_it)
		{
			haystack_it++;
			needle_it++;
		}
		if (*needle_it == '\0')
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
