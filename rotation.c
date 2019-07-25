/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/25 17:23:45 by tkelsie          ###   ########.fr       */
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
	int max_;
	t_point		**new_cords;

	i = 0;
	max_ = megastruct->coords_in_x_quantity * megastruct->str_quantity;
	while (i < max_)
	{
		iso(megastruct->coords[i]);
		megastruct->offset = (megastruct->offset > megastruct->coords[i]->x) ?
		megastruct->coords[i]->x : megastruct->offset;
		i++;
	}
	i = 0;
	while (i < max_)
		megastruct->coords[i++]->x -= megastruct->offset;
}
