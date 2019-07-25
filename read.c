/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/25 17:05:08 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

void	fdf_read(t_mega *megastruct)
{
	char		*argv;
	char		**splitted_argv;
	t_stroka	*tmp;

	megastruct->str_quantity = 0;
	megastruct->zoom = 11;
	while (get_next_line(megastruct->fd, &argv))
	{
		if (!(splitted_argv = ft_strsplit(argv, ' ')))
			pizdec('b');
		if (megastruct->str_quantity == 0)
			tmp = stroka_new(splitted_argv);
		else
			stroka_push_front(&tmp, splitted_argv);
		megastruct->str_quantity++;
	}
	stroka_reverse(&tmp);
	megastruct->coords_in_x_quantity = ft_ncounter(argv, ' ') + 1;
	megastruct->max_ = megastruct->str_quantity * megastruct->coords_in_x_quantity;
	ft_strdel(&argv);
	megastruct->coords = fdf_cords_point(tmp, megastruct->max_, megastruct->zoom);
}

void	set_color(char *data, t_point *cord)
{
	char	**row;
	int		i;

	if (ft_strchr(data, ','))
	{
		row = ft_strsplit(data, ',');
		cord->z = ft_atoi(row[0]);
		cord->color = ft_atoi_base(row[1], 16);
		i = 0;
		while (row[i])
			ft_strdel(&row[i++]);
		free(row);
		row = NULL;
	}
	else
	{
		cord->z = ft_atoi(data);
		cord->color = 0x0F00F0F;
	}
}

t_point	**fdf_cords_point(t_stroka *tmp, int size, int zoom)
{
	t_point		**cords;
	int			x;
	int			k;
	int			y;


	if (!(cords = (t_point **)malloc(sizeof(t_point *) * size)))
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
			cords[k]->x = x * zoom;
			cords[k]->y = y * zoom;
			set_color(tmp->data[x++], cords[k++]);
			//printf("%d %d %d %d\n", cords[k-1]->x, cords[k-1]->y, cords[k-1]->z, cords[k-1]->color);
		}
		//printf("\n");
		tmp = tmp->next;
		y++;
	}
	return (cords);
}
