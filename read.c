/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 10:52:10 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	fdf_read(t_mega *megastruct)
{
	char		*argv;
	char		**splitted_argv;
	t_stroka	*tmp;

	megastruct->max_y = 0;
	megastruct->zoom = 25;
	while (get_next_line(megastruct->fd, &argv))
	{
		if (!(splitted_argv = ft_strsplit(argv, ' ')))
			pizdec('b');
		if (megastruct->max_y == 0)
			tmp = stroka_new(splitted_argv);
		else
			stroka_push_front(&tmp, splitted_argv);
		megastruct->max_y++;
	}
	stroka_reverse(&tmp);
	megastruct->max_x = ft_ncounter(argv, ' ') + 1;
	megastruct->max_ = megastruct->max_y * megastruct->max_x;
	ft_strdel(&argv);
	megastruct->coords = fdf_cords_point(tmp, megastruct);
}

void	set_color(char *data, t_point *cord, int zoom)
{
	char	**row;
	int		i;

	if (ft_strchr(data, ','))
	{
		row = ft_strsplit(data, ',');
		cord->z = ft_atoi(row[0]) * zoom;
		cord->color = ft_atoi_base(row[1], 16);
		i = 0;
		while (row[i])
			ft_strdel(&row[i++]);
		free(row);
		row = NULL;
	}
	else
	{
		cord->z = ft_atoi(data) * zoom;
		cord->color = -1;
	}
}

void	min_max_z(int tmp, t_point *z, int k)
{
	if (k == 0)
	{
		z->y = tmp;
		z->x = tmp;
	}
	else
	{
		z->y = (tmp > z->y) ? tmp : z->y;
		z->x = (tmp < z->y) ? tmp : z->x;
	}
}

t_point	**fdf_cords_point(t_stroka *tmp, t_mega *megastruct)
{
	t_point		**cords;
	int			x;
	int			k;
	int			y;

	if (!(cords = (t_point **)malloc(sizeof(t_point *) * megastruct->max_)))
		pizdec('e');
	k = 0;
	y = 0;
	while (tmp)
	{
		x = 0;
		while (tmp->data[x])
		{
			if (!(cords[k] = (t_point *)malloc(sizeof(t_point))))
				pizdec('f');
			set_color(tmp->data[x++], cords[k], megastruct->zoom);
			min_max_z(cords[k]->z, &megastruct->min_max_z, k);
			cords[k]->x = x * megastruct->zoom;
			cords[k++]->y = y * megastruct->zoom;
		}
		tmp = tmp->next;
		y++;
	}
	return (cords);
}
