/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:51:44 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 17:37:56 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_mega *megastruct)
{
	int i;
	int max_x;
	int max_y;

	i = 0;
	max_x = megastruct->coords_in_x_quantity;
	max_y = megastruct->str_quantity;
	while (i < (max_x * max_y) - 1)
	{
		if (megastruct->coords[i]->x / megastruct->zoom < max_x - 1)
			draw_line(*megastruct->coords[i], *megastruct->coords[i + 1], *megastruct);
		if (megastruct->coords[i]->y / megastruct->zoom < max_y - 1)
			draw_line(*megastruct->coords[i], *megastruct->coords[i + max_x], *megastruct);	
		i++;
	}
}

void	find_point_in_million(int x, int  y, t_mega megastruct)
{
	if ((y < HIGHT) && (y >= 0) && (x < WIDTH) && (x >= 0))
		megastruct.data_adress[y * WIDTH + x] = 65146;
}

static int	barely_equals(double c, double b)
{
	double a;

	a = c - b;
	return (((a < 0.) ? -a : a) < 1);
}

void		draw_line(t_point a, t_point b, t_mega megastruct)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (!barely_equals(cur.x, b.x) || !barely_equals(cur.y, b.y))
	{
		//cur.color = get_color(cur, a, b, delta);
		find_point_in_million(cur.x, cur.y, megastruct);
		if ((error[1] = error[0] << 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		error[1] < delta.x ? cur.y += sign.y : 0;
		error[1] < delta.x ? error[0] += delta.x : 0;
	}
}