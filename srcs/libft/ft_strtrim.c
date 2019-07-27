/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:55:57 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 18:43:19 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(const char *s)
{
	size_t		e;
	size_t		c;
	char		*dest;

	if (!s)
		return (NULL);
	if (s && ft_strcmp(s, ""))
	{
		while ((*s == ' ' || *s == '\n' || *s == '\t') && *s != '\0')
			s++;
	}
	e = (s && ft_strcmp(s, "")) ? ft_strlen(s) - 1 : 0;
	if (s && ft_strcmp(s, ""))
	{
		while (e && s && (s[e] == ' ' || s[e] == '\n' || s[e] == '\t'))
			e--;
	}
	if (!(dest = ft_strnew(e + 1)))
		return (NULL);
	c = 0;
	while (s && e && c <= e && e != 0)
		dest[c++] = *s++;
	dest[c] = '\0';
	return (dest);
}
