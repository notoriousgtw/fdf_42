/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:33:57 by mhurd             #+#    #+#             */
/*   Updated: 2018/06/18 16:34:52 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	key_hook_rotation(int keycode, t_data *d)
{
	if (keycode == KEY_EIGHT)
		d->xr += 0.01;
	else if (keycode == KEY_TWO)
		d->xr -= 0.01;
	else if (keycode == KEY_SIX)
		d->yr += 0.01;
	else if (keycode == KEY_FOUR)
		d->yr -= 0.01;
	else if (keycode == KEY_NINE)
		d->zr += 0.01;
	else if (keycode == KEY_SEVEN)
		d->zr -= 0.01;
}

static	void	key_hook_translation(int keycode, t_data *d)
{
	if (keycode == KEY_W)
		d->ytrans += 5;
	else if (keycode == KEY_S)
		d->ytrans -= 5;
	else if (keycode == KEY_A)
		d->xtrans += 5;
	else if (keycode == KEY_D)
		d->xtrans -= 5;
}

static	void	key_hook_scale(int keycode, t_data *d)
{
	if (keycode == KEY_PLUS)
		d->scale += 0.1;
	else if (keycode == KEY_MINUS)
		d->scale = fabs(d->scale - 0.1);
}

int				expose_hook(t_data *d)
{
	draw_reload(d);
	return (0);
}

int				key_hook(int keycode, t_data *d)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(d->mlx, d->win);
		exit(0);
	}
	key_hook_rotation(keycode, d);
	key_hook_translation(keycode, d);
	key_hook_scale(keycode, d);
	draw_reload(d);
	return (0);
}
