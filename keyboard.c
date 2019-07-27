/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 10:58:25 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keyboard(int key, t_mega *megastruct)
{
	if (key == 53)
		exit(0);
	if (key == 123 || key == 124)
		shift_x(megastruct, key);
	if (key == 125 || key == 126)
		shift_y(megastruct, key);
	if (key == 69 || key == 78)
		zoom(megastruct, key);
	fill_backgound(0, megastruct);
	interface(megastruct);
	draw(megastruct);
	mlx_put_image_to_window(megastruct->discriptor, megastruct->win,
		megastruct->img, 0, 55);
	fill_backgound(0, megastruct);
	return (0);
}
