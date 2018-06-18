/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:59:12 by gwood             #+#    #+#             */
/*   Updated: 2018/02/27 18:56:36 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*lst_it;

	if (!lst)
		return (NULL);
	lst_it = f(lst);
	new = lst_it;
	while (lst->next)
	{
		lst = lst->next;
		if (!(lst_it->next = f(lst)))
		{
			free(lst_it->next);
			return (NULL);
		}
		lst_it = lst_it->next;
	}
	return (new);
}
