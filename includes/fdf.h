/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 16:06:16 by mhurd             #+#    #+#             */
/*   Updated: 2018/06/17 13:40:40 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "libgfx.h"
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

/*
** KEYS
*/

# define KEY_ESC 53

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_BUTTON 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEY_W	13
# define KEY_S	1
# define KEY_A	0
# define KEY_D	2

# define KEY_ONE	83
# define KEY_TWO	84
# define KEY_THREE	85
# define KEY_FOUR	86
# define KEY_FIVE	87
# define KEY_SIX	88
# define KEY_SEVEN	89
# define KEY_EIGHT	91
# define KEY_NINE	92

# define KEY_PLUS   69
# define KEY_MINUS  78

t_plot		*parse_file(char *filename);
void		draw_everything(t_data *d);
int			key_hook(int keycode, t_data *d);
void		draw_reload(t_data *d);
void		draw_map(t_data *d);
void		ft_exit(void);
void		ft_error(char *s);
void		ft_error_unknown(void);
int			expose_hook(t_data *d);
#endif
