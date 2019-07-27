/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 15:51:44 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 11:43:11 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < (megastruct->max_) - 1)
	{
		if (i % megastruct->max_x < megastruct->max_x - 1)
			draw_line(*megastruct->coords[i], *megastruct->coords[i + 1],
			*megastruct);
		if (i / megastruct->max_x < megastruct->max_y - 1)
			draw_line(*megastruct->coords[i],
			*megastruct->coords[i + megastruct->max_x], *megastruct);
		i++;
	}
}

void	find_point_in_million(t_point cur, t_mega megastruct)
{
	if ((cur.y < HIGHT) && (cur.y >= 0) && (cur.x < WIDTH) && (cur.x >= 0))
		megastruct.data_adress[cur.y * WIDTH + cur.x] = cur.color;
}

void	draw_line(t_point a, t_point b, t_mega megastruct)
{
	int		sign[2];
	int		error[2];
	t_point	cur;
	t_point	delta;

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign[0] = a.x < b.x ? 1 : -1;
	sign[1] = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		cur.color = get_color(cur, a, b, delta);
		find_point_in_million(cur, megastruct);
		error[1] = 2 * error[0];
		error[1] > -delta.y ? error[0] -= delta.y : 0;
		error[1] > -delta.y ? cur.x += sign[0] : 0;
		error[1] < delta.x ? error[0] += delta.x : 0;
		error[1] < delta.x ? cur.y += sign[1] : 0;
	}
}
