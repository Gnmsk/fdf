/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:17:23 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 18:46:01 by tkelsie          ###   ########.fr       */
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
	megastruct->coords_in_x_quantity =  ft_ncounter(argv, ' ') + 1;
	ft_strdel(&argv);
	megastruct->coords = fdf_cords_point(tmp, megastruct->str_quantity * megastruct->coords_in_x_quantity, megastruct->zoom);
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
			cords[k]->z = ft_atoi(tmp->data[x]);
			cords[k]->x = x * zoom;
			cords[k]->y = y * zoom;
			cords[k++]->color = (ft_atoi(tmp->data[x++]) > 0) ? 'r' : 'w';
			//printf("%d %d %d %c\n", cords[k-1]->x, cords[k-1]->y, cords[k-1]->z, cords[k-1]->color);
		}
		//printf("\n");
		tmp = tmp->next;
		y++;
	}
	return (cords);
}
