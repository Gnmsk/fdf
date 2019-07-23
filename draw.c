/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:51:44 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/23 17:00:46 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_mega megastruct)
{
	int i;

	i = 0;

	while (i < 25)
	{
		if (megastruct.coords[i]->x < megastruct.coords_in_x_quantity - 1)
			draw_line(*megastruct.coords[i], *megastruct.coords[i + 1],  megastruct.coords_in_x_quantity);
		if (megastruct.coords[i + megastruct.coords_in_x_quantity])
			draw_line(*megastruct.coords[i], *megastruct.coords[i + megastruct.coords_in_x_quantity], megastruct.coords_in_x_quantity);
		i++;
		printf("\ni: %d; ", i);
	}
}

int		find_point_in_million(int x, int  y, int	max_x)
{
	int i;

	i = y * max_x + x;
	printf("%d ", i);
	return (i * 4);
}

void	draw_line(t_point a, t_point b, int max_x)
{
	int		delta[2];
	int		cords[4] = {a.x, a.y, b.x, b.y};
	int		err_ystep[2];
	int		xy[2];
	int		steep;
	int		tmp;

	steep = ft_abs(b.y - a.y) > ft_abs(b.x - a.x) ? 1 : 0;
	if (steep)
	{
		cords[0] = a.y;
		cords[1] = a.x;
		cords[2] = b.y;
		cords[3] = b.x;
	}
	if (cords[0] > cords[1])
	{
		tmp = cords[0];
		cords[0] = cords[1];
		cords[1] = tmp;
		tmp = cords[3];
		cords[3] = cords[2];
		cords[2] = tmp;
	}
	delta[0] = cords[1] - cords[0];
	delta[1] = ft_abs(cords[3] - cords[2]);
	err_ystep[0] = delta[0] / 2;
	err_ystep[1] = (cords[2] < cords[3] ? 1 : -1);
	xy[0] = cords[0];
	xy[1] = cords[2];
	while (xy[0] <= cords[1])
	{
		find_point_in_million(steep ? xy[1] : xy[0], steep ? xy[0] : xy[1], max_x);
		err_ystep[0] -= delta[1];
		if (err_ystep[0] < 0)
		{
			xy[1] += err_ystep[1];
			err_ystep[0] += delta[0];
		}
		xy[0]++;
	}
}
