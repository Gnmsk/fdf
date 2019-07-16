/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:13:08 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 21:37:37 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t c;

	if (ft_strlen(dst) >= size)
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	c = 0;
	while (c + i < size - 1 && src[c])
	{
		dst[i + c] = src[c];
		c++;
	}
	dst[i + c] = '\0';
	return (i + ft_strlen(src));
}
