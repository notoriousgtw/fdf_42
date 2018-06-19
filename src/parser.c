/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwood <gwood@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/30 14:34:31 by mhurd             #+#    #+#             */
/*   Updated: 2018/06/18 17:21:02 by gwood            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		clean(t_list **rows, char ***buff)
{
	t_list	*tmp;

	free((*rows)->content);
	tmp = *rows;
	*rows = (*rows)->next;
	free(tmp);
	ft_freestrarr(*buff);
}

static t_plot	*list_to_array(t_plot *plot, t_list *rows)
{
	int		y;
	int		x;
	char	**buff;
	int		z;

	plot->points = (t_vertex ***)ft_memalloc(sizeof(t_vertex **)
		* plot->height);
	y = -1;
	while (++y < plot->height)
	{
		plot->points[y] = (t_vertex **)ft_memalloc(sizeof(t_vertex *)
			* plot->width);
		buff = ft_strsplit(rows->content, ' ');
		x = -1;
		while (++x < plot->width)
		{
			z = ft_atoi(buff[x]);
			plot->points[y][x] = ft_make_vertex(x, y, z);
			plot->z_min = MIN(z, plot->z_min);
			plot->z_max = MAX(z, plot->z_max);
		}
		clean(&rows, &buff);
	}
	return (plot);
}

static t_plot	*make_plot(void)
{
	t_plot *plot;

	plot = (t_plot *)ft_memalloc(sizeof(t_plot));
	plot->width = -1;
	plot->z_min = 2147483647;
	plot->z_max = -2147483648;
	return (plot);
}

int				check_fd(int fd, char *filename)
{
	if (fd < 0)
		ft_error(ft_strcat(filename, " doesn't exist"));
	return (1);
}

t_plot			*parse_file(char *filename)
{
	char	*buff;
	int		result;
	int		fd;
	t_list	*list;
	t_plot	*plot;

	fd = open(filename, O_RDONLY);
	list = NULL;
	plot = make_plot();
	while ((result = ft_gnl(fd, &buff)) && check_fd(fd, filename))
	{
		if (plot->width == -1)
			plot->width = ft_cntwrd(buff, ' ');
		if (plot->width != ft_cntwrd(buff, ' '))
			ft_error("Invalid Map");
		ft_lstapp(&list, ft_lstnew(buff, ft_strlen(buff) + 1));
		(plot->height)++;
		free(buff);
	}
	if (result < 0)
		ft_error_unknown();
	close(fd);
	return (list_to_array(plot, list));
}
