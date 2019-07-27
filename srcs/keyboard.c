/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 21:12:59 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_mega *megastruct)
{
	megastruct->iso_coords = copy_structure(megastruct);
	zoom(megastruct, megastruct->zoom);
	if (megastruct->proj == 1)
		megastruct->proj = 0;
	else if (megastruct->proj == 0)
		rotation(megastruct);
	shift(megastruct);
	centre(megastruct);
}

void	movements(int key, t_mega *megastruct)
{
	if (key == 83)
		megastruct->alpha -= 0.05;
	if (key == 84)
		megastruct->alpha += 0.05;
	if (key == 85)
		megastruct->beta -= 0.05;
	if (key == 86)
		megastruct->beta += 0.05;
	if (key == 87)
		megastruct->gamma -= 0.05;
	if (key == 88)
		megastruct->gamma += 0.05;
	megastruct->iso_coords = copy_structure(megastruct);
	zoom(megastruct, megastruct->zoom);
	rotation(megastruct);
	shift(megastruct);
	centre(megastruct);
}

void	zooming(int key, t_mega *megastruct)
{
	megastruct->iso_coords = copy_structure(megastruct);
	if (key == 69)
		megastruct->zoom += 3;
	else if (key == 78 && megastruct->zoom > 3)
		megastruct->zoom -= 3;
	zoom(megastruct, megastruct->zoom);
	if (megastruct->proj == 1)
		rotation(megastruct);
	centre(megastruct);
}

int		keyboard(int key, t_mega *megastruct)
{
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		shift_xy(megastruct, key);
	if (key == 69 || key == 78)
		zooming(key, megastruct);
	if (key == 49)
		projection(megastruct);
	if (key >= 83 && key <= 88)
		movements(key, megastruct);
	if (key == 82)
		default_state(megastruct);
	display_map(megastruct);
	return (0);
}
