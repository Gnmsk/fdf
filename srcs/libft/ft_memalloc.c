/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:28:51 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/12 20:34:03 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = NULL;
	if (size)
	{
		if (!(mem = (unsigned char *)malloc(sizeof(mem) * (size))))
			return (NULL);
		while (size)
			mem[--size] = 0;
	}
	return ((void *)mem);
}
