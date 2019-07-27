/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 16:22:43 by tkelsie          ###   ########.fr       */
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
		megastruct->iso_coords[i]->y += megastruct->offset.color;
		i++;
	}
	megastruct->proj = 1;
}

void	shift_x(t_mega *megastruct, int key)
{
	int i;
	int step;

	i = 0;
	step = (key == 123) ? -4 : 4;
	while (i < megastruct->max_)
		megastruct->iso_coords[i++]->x += step;
}

void	shift_y(t_mega *megastruct, int key)
{
	int i;
	int step;

	i = 0;
	step = (key == 125) ? 4 : -4;
	while (i < megastruct->max_)
		megastruct->iso_coords[i++]->y += step;
}

void	zoom(t_mega *megastruct, int key)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		if (key == 69)
		{
			megastruct->iso_coords[i]->y *= 2;
			megastruct->iso_coords[i]->x *= 2;
			megastruct->iso_coords[i]->z *= 2;
		}
		else if (key == 78)
		{
			megastruct->iso_coords[i]->y /= 2;
			megastruct->iso_coords[i]->x /= 2;
			megastruct->iso_coords[i]->z /= 2;
		}
		i++;
	}
}

void	zoom_base(t_mega *megastruct, double zoom)
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

