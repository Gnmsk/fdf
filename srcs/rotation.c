/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 18:49:29 by tkelsie          ###   ########.fr       */
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

static void			rotation_x(t_point *p, t_mega *megastruct)
{
	int				previous_y;

	previous_y = p->y;
	p->y = cos(megastruct->alpha) * previous_y + sin(megastruct->alpha) * p->z;
	p->z = -sin(megastruct->alpha) * previous_y + cos(megastruct->alpha) * p->z;
}

static void			rotation_y(t_point *p, t_mega *megastruct)
{
	int				previous_x;

	previous_x = p->x;
	p->x = previous_x * cos(megastruct->beta) + p->z * sin(megastruct->beta);
	p->z = -previous_x * sin(megastruct->beta) + p->z * cos(megastruct->beta);
}

static void			rotation_z(t_point *p, t_mega *megastruct)
{
	int				previous_x;
	int				previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = cos(megastruct->gamma) * previous_x \
		- sin(megastruct->gamma) * previous_y;
	p->y = sin(megastruct->gamma) * previous_x \
		+ cos(megastruct->gamma) * previous_y;
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
	{
		rotation_x(megastruct->iso_coords[i], megastruct);
		rotation_y(megastruct->iso_coords[i], megastruct);
		rotation_z(megastruct->iso_coords[i], megastruct);
		iso(megastruct->iso_coords[i++], &megastruct->offset);
	}
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