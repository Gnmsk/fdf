/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:50:47 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/13 16:50:42 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t			n;
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	ch;

	n = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n < len)
	{
		dest[n] = source[n];
		if (source[n] == ch)
			return (dst + n + 1);
		n++;
	}
	return (NULL);
}
