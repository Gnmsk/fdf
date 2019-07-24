/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:14:34 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 17:47:48 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
		i++;
	}
	return (n);
}

static size_t	ft_strnlen(char const *s, char c)
{
	size_t		n;

	n = 0;
	while (*s != '\0' && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

static char		**ft_strfill(char **dest, char const *s, char c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && *s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(dest[i] = ft_strnew(ft_strnlen(s, c))))
		{
			while (i--)
				ft_memdel((void *)dest[i]);
			return (NULL);
		}
		dest[i] = ft_strncpy(dest[i], s, ft_strnlen(s, c));
		i++;
		while (*s != c && *s != '\0')
			s++;
	}
	dest[n] = 0;
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		n;
	char		**dest;

	if (!s)
		return (0);
	n = ft_count_words(s, c);
	if (!(dest = (char **)malloc(sizeof(dest) * n + 1)))
		return (NULL);
	return (dest = ft_strfill(dest, s, c, n) ? dest : 0);
}
