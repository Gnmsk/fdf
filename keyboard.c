/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:15:13 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 14:48:01 by tkelsie          ###   ########.fr       */
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
	if (key == 49)
		rotation2(megastruct);
	display_map(megastruct);
	return (0);
}
