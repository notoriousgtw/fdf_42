/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:39:09 by gwood             #+#    #+#             */
/*   Updated: 2018/05/29 17:38:40 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_valid(char c)
{
	char	*valid_chars;

	valid_chars = "0123456789abcdef";
	while (*valid_chars)
		if (*valid_chars++ == c)
			return (1);
	return (0);
}

static	int	get_val(char c)
{
	char	*valid_chars;
	char	*offset;

	valid_chars = "0123456789abcdef";
	offset = valid_chars - 1;
	while (*++offset)
		if (*offset == c)
			return (offset - valid_chars);
	return (0);
}

static	int	numlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && is_valid(s[i]))
		i++;
	return (i);
}

int			ft_atoi_base(const char *s, int base)
{
	int		i;
	int		digits;
	int		isneg;

	isneg = 0;
	i = 0;
	s = ft_strtolower(s);
	while (ft_iswspace(*s))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		isneg = 1;
		s++;
	}
	digits = numlen(s);
	while (*s != '\0' && is_valid(*s))
		i += get_val(*s++) * ft_power(base, digits--);
	if (isneg)
		return (-i);
	else
		return (i);
}
