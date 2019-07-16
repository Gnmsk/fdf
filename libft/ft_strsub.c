/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:39:29 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/21 14:16:19 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (s && len && (sub = ft_strnew(len)))
	{
		sub[len] = '\0';
		while (len-- > 0)
			sub[len] = s[start + len];
		return (sub);
	}
	if (len == 0)
	{
		if (!(sub = ft_strnew(1)))
		{
			ft_memdel((void *)sub);
			return (NULL);
		}
		sub[0] = '\0';
		return (sub);
	}
	return (NULL);
}
