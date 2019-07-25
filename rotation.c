/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 19:50:43 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/25 17:16:43 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_point  *p, t_point *n)
{
	int previous_x;
	int previous_y;

	previous_x = p->x;
	previous_y = p->y;
	n->x = (previous_x - previous_y) * cos(0.523599);
	//printf("%f ", (previous_x - previous_y) * cos(0.523599));
	//printf("%f\n", -(p->z) + (previous_x + previous_y) * sin(0.523599));
	n->y = -(p->z) + (previous_x + previous_y) * sin(0.523599);
	n->z = p->z;
	n->color = p->color;
}

void	rotation(t_mega *megastruct)
{
	int i;
	int max_;
	int	offset;
	t_point		**new_cords;

	i = 0;
	offset = 0;
	max_ = megastruct->coords_in_x_quantity* megastruct->str_quantity;
	if (!(new_cords = (t_point **)malloc(sizeof(t_point *) * max_)))
		pizdec('e');
	while (i < max_)
	{
		if (!(new_cords[i] = (t_point *)malloc(sizeof(t_point))))
				pizdec('f');
		iso(megastruct->coords[i], new_cords[i]);
		offset = (offset > new_cords[i]->x) ? new_cords[i]->x : offset;
		i++;
	}
	megastruct->offset = offset;
	i = 0;
	while (i < max_)
		new_cords[i++]->x -= offset;
	i = 0;
	while (i < max_)
	{
		printf("%d\t%d %d %d %d\n", i, new_cords[i]->x, new_cords[i]->y, new_cords[i]->z, new_cords[i]->color);
		i++;
	}
	megastruct->coords = new_cords;
	printf("\n%d", offset);
}
