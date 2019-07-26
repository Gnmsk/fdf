/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/26 21:50:39 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *p, t_point *offset)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -(p->z) + (previous_x + previous_y) * sin(0.523599);
	offset->x = (offset->x > p->x) ? p->x : offset->x;
	offset->y = (offset->y > p->y) ? p->y : offset->y;
}

void	rotation(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
		iso(megastruct->coords[i++], &megastruct->offset);
	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->coords[i]->x -= megastruct->offset.x;
		megastruct->coords[i]->x += megastruct->offset.z;
		megastruct->coords[i]->y -= megastruct->offset.y;
		megastruct->coords[i++]->y += megastruct->offset.color;
	}
}

void	shift_x(t_mega *megastruct, int step)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->coords[i++]->x += step;
	}
}

void	shift_y(t_mega *megastruct, int step)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->coords[i++]->y += step;
	}
}
