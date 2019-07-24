/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:55:28 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 20:22:08 by tkelsie          ###   ########.fr       */
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

double	percentage(t_point delta, t_point start, t_point end, t_point current)
{
	double percentage;

	if (delta.x > delta.y)
		return (percent(start.x, end.x, current.x));
	return (percent(start.y, end.y, current.y));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	pctg;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		pctg = percent(start.x, end.x, current.x);
	else
		pctg = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, pctg);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, pctg);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, pctg);
	return ((red << 16) | (green << 8) | blue);
}
