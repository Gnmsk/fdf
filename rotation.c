/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/25 16:01:27 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_point  *p)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = -(p->z) + (previous_x + previous_y) * sin(0.523599);
}

void	rotation(t_mega *megastruct)
{
	int i;
	int max_x;
	int max_y;

	i = 0;
	max_x = megastruct->coords_in_x_quantity;
	max_y = megastruct->str_quantity;
	while (i < 190)
	{
		iso(megastruct->coords[i]);
		printf("%d %d %d %d\n", megastruct->coords[i]->x, megastruct->coords[i]->y, megastruct->coords[i]->z, megastruct->coords[i]->color);
		i++;
	}
}
