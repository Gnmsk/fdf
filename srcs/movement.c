/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:24:39 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 20:47:04 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	shift_xy(t_mega *megastruct, int key)
{
	int i;
	int step;

	i = 0;
	step = (key == 123 || key == 126) ? -4 : 4;
	if (key == 123 || key == 124)
	{
		while (i < megastruct->size)
			megastruct->iso_coords[i++]->x += step;
		megastruct->shift.x += ((key == 123) ? -4 : 4);
	}
	else if (key == 125 || key == 126)
	{
		while (i < megastruct->size)
			megastruct->iso_coords[i++]->y += step;
		megastruct->shift.y += ((key == 125) ? 4 : -4);
	}
}

void	zoom(t_mega *megastruct, double zoom)
{
	int i;

	i = 0;
	while (i < megastruct->size)
	{
		megastruct->iso_coords[i]->x *= zoom;
		megastruct->iso_coords[i]->y *= zoom;
		megastruct->iso_coords[i++]->z *= zoom;
	}
}

void	shift(t_mega *megastruct)
{
	int i;

	i = 0;
	while (i < megastruct->size)
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
	while (i < megastruct->size)
	{
		megastruct->iso_coords[i]->x += (WIDTH -
		(megastruct->max_x * megastruct->zoom)) / 2;
		megastruct->iso_coords[i]->y += (-150) + (HIGHT -
		(megastruct->max_y * megastruct->zoom)) / 2;
		if (megastruct->proj == 1)
		{
			megastruct->iso_coords[i]->x += ((megastruct->coords[i]->x -
			megastruct->coords[i]->y) * cos(0.523599)) / 2;
			megastruct->iso_coords[i]->y += ((megastruct->coords[i]->x +
			megastruct->coords[i]->y) * sin(0.523599)) / 2 -
			megastruct->iso_coords[i]->z;
		}
		i++;
	}
}

void	default_state(t_mega *megastruct)
{
	megastruct->alpha = 0;
	megastruct->beta = 0;
	megastruct->gamma = 0;
	megastruct->shift.x = 0;
	megastruct->shift.y = 0;
	megastruct->proj = 0;
	megastruct->zoom = DEFAULTZOOM;
	megastruct->iso_coords = copy_structure(megastruct);
	zoom(megastruct, megastruct->zoom);
	centre(megastruct);
}
