/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:25:09 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/15 21:53:06 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*res;
	size_t		len;

	res = NULL;
	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		len = ft_strlen(s);
		res[len] = '\0';
		while (len-- > 0)
			res[len] = (char)f(len, s[len]);
	}
	return (res);
}
