/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:21:10 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/12 23:06:32 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dst, const char *src)
{
	int		i;
	size_t	c;

	i = 0;
	c = 0;
	if (src[0] == '\0')
		return ((char *)dst);
	while (dst[i] != '\0')
	{
		c = 0;
		if (dst[i] == src[c])
		{
			while (dst[i + c] == src[c] && dst[i + c] != '\0' && src[c] != '\0')
				c++;
			if (c == ft_strlen(src))
				return ((char *)&dst[i]);
		}
		i++;
	}
	return (NULL);
}
