/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 14:48:53 by tkelsie          ###   ########.fr       */
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

void	iso2(t_point *p, t_point *offset)
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

void	rotation2(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
		iso2(megastruct->iso_coords[i++], &megastruct->offset);
	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->x -= megastruct->offset.x;
		megastruct->iso_coords[i]->x += megastruct->offset.z;
		megastruct->iso_coords[i]->y -= megastruct->offset.y;
		megastruct->iso_coords[i]->y += megastruct->offset.color;
		i++;
	}
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
	megastruct->iso_coords = copy_structure(megastruct);
	if (key == 69)
		megastruct->zoom *= 2;
	else if (key == 78)
		megastruct->zoom /= 2;
	while (i < megastruct->max_)
	{
		megastruct->iso_coords[i]->y *= megastruct->zoom;
		megastruct->iso_coords[i]->x *= megastruct->zoom;
		megastruct->iso_coords[i]->z *= megastruct->zoom;
		i++;
	}
}

void	scaling(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->max_)
	{
		megastruct->coords[i]->x *= megastruct->zoom;
		megastruct->coords[i]->y *= megastruct->zoom;
		megastruct->coords[i]->z *= megastruct->zoom;
		i++;
	}
	megastruct->min_max_z.x *= megastruct->zoom;
	megastruct->min_max_z.y *= megastruct->zoom;
}
