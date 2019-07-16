/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:36:47 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/15 21:52:44 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*res;
	size_t		len;

	res = NULL;
	if (s && f && (res = ft_strnew(ft_strlen(s))))
	{
		len = ft_strlen(s);
		res[len] = '\0';
		while (len-- > 0)
			res[len] = (char)f(s[len]);
	}
	return (res);
}
