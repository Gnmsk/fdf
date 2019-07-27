/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 17:37:41 by tkelsie          ###   ########.fr       */
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
	megastruct->offset.x = 0;
	megastruct->offset.y = 0;
	megastruct->offset.z = 0;
	megastruct->offset.color = 0;
	while (i < megastruct->max_)
		iso(megastruct->iso_coords[i++], &megastruct->offset);
	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->x -= megastruct->offset.x;
		megastruct->iso_coords[i]->x += megastruct->offset.z;
		megastruct->iso_coords[i]->y -= megastruct->offset.y;
		megastruct->iso_coords[i++]->y += megastruct->offset.color;
	}
	megastruct->proj = 1;
}

void	shift_xy(t_mega *megastruct, int key)
{
	int i;
	int step;

	i = 0;
	step = (key == 123 || key == 126) ? -4 : 4;
	if (key == 123 || key == 124)
	{
		while (i < megastruct->max_)
			megastruct->iso_coords[i++]->x += step;
		megastruct->shift.x += ((key == 123) ? -4 : 4);
	}
	else if (key == 125 || key == 126)
	{
		while (i < megastruct->max_)
			megastruct->iso_coords[i++]->y += step;
		megastruct->shift.y += ((key == 125) ? 4 : -4);
	}
}

void	zoom(t_mega *megastruct, double zoom)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->x *= zoom;
		megastruct->iso_coords[i]->y *= zoom;
		megastruct->iso_coords[i]->z *= zoom;
		i++;
	}
	megastruct->min_max_z.x *= zoom;
	megastruct->min_max_z.y *= zoom;
}

void	shift(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->x += megastruct->shift.x;
		megastruct->iso_coords[i]->y += megastruct->shift.y;
		i++;
	}
}

void	centre(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->x += WIDTH / 2 -
		(megastruct->max_x * megastruct->zoom) / 2;
		megastruct->iso_coords[i++]->y += HIGHT / 2 -
		(megastruct->max_y * megastruct->zoom) / 2;
	}
}
