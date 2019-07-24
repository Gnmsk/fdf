/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:51:44 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 18:19:55 by tkelsie          ###   ########.fr       */
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
		megastruct.data_adress[y * WIDTH + x] = 255;
}

void		draw_line(t_point a, t_point b, t_mega megastruct)
{
	int		delta[2];
	int		sign[2];
	int		error[2];
	t_point	cur;

	delta[0] = ft_abs(b.x - a.x);
	delta[1] = ft_abs(b.y - a.y);
	sign[0] = a.x < b.x ? 1 : -1;
	sign[1] = a.y < b.y ? 1 : -1;
	error[0] = delta[0] - delta[1];
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		//cur.color = get_color(cur, a, b, delta);
		find_point_in_million(cur.x, cur.y, megastruct);
		error[1] = 2 * error[0];
		error[1] > -delta[1] ? error[0] -= delta[1] : 0;
		error[1] > -delta[1] ? cur.x += sign[0] : 0;
		error[1] < delta[0] ? cur.y += sign[1] : 0;
		error[1] < delta[0] ? error[0] += delta[0] : 0;
	}
}
