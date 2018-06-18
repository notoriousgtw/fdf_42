/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 15:35:03 by mhurd             #+#    #+#             */
/*   Updated: 2018/06/17 13:40:24 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	display_usage(char *av)
{
	ft_putstr("usage: ");
	ft_putstr(av);
	ft_putendl(" input_file");
}

void	display_controls(void)
{
	ft_putendl("CONTROLS:\n\
Translation:\n\
	Y: Key: W, S\n\
	X: Key: A, D\n\
Rotation:\n\
	X: Keypad: 2, 8\n\
	Y: Keypad: 4, 6\n\
	Z: Keypad: 7, 9\n\
Zoom:\n\
	IN: Keypad: +\n\
	OUT: Keypad: -");
}

int		main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = (t_data *)ft_memalloc(sizeof(t_data));
		if (!data)
			ft_error("Malloc Error");
		data->plot = parse_file(av[1]);
		display_controls();
		draw_everything(data);
	}
	else
		display_usage(av[0]);
	return (0);
}
