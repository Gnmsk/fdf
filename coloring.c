/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:55:28 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 12:55:05 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		color(int start, int end, double percentage)
{
	int red;
	int green;
	int blue;

	red = get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF, percentage);
	green = get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF, percentage);
	blue = get_light(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int		get_color(t_point cur, t_point start, t_point end, t_point delta)
{
	double percentage;

	if (cur.color == end.color)
		return (end.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	return (color(start.color, end.color, percentage));
}

void	gradient(t_mega *megastruct)
{
	int		i;
	double	pct;

	i = 0;
	while (i < megastruct->max_)
	{
		pct = percent(megastruct->min_max_z.x, megastruct->min_max_z.y,
		megastruct->coords[i]->z);
		megastruct->coords[i++]->color = color(RED, YELLOW, pct);
	}
}
