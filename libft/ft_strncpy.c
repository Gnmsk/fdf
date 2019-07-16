/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:44:21 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/13 16:23:20 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t n;

	n = 0;
	while (src[n] != '\0' && n < len)
	{
		dst[n] = src[n];
		n++;
	}
	while (n < len)
		dst[n++] = '\0';
	return (dst);
}
