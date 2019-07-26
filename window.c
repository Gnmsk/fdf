/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:03:08 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/26 22:24:01 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			interface(t_mega *megastructura)
{
	mlx_string_put(megastructura->discriptor, megastructura->win, 0, 0, \
	0xFF, "left-right-up-down for move on x/y/z axis");
}
