/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 11:51:45 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 11:52:51 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordscnt(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (*(s + i))
	{
		while (*(s + i) == c)
			i++;
		if (*(s + i) != c && *(s + i) != '\0')
			count++;
		while (*(s + i) != c && *(s + i) != '\0')
			i++;
	}
	return (count);
}

static void	ft_getwordptr(char const *s, char c, char **strt, char **nd)
{
	if (*s != c && *strt == NULL)
		*strt = (char *)s;
	if (*s == c && *strt != NULL && *nd == NULL)
		*nd = (char *)s;
	if (*s != c && *(s + 1) == '\0' && *strt != NULL && *nd == NULL)
		*nd = (char *)(s + 1);
}

static char	*ft_getword(char const *s, char **strt, char **nd)
{
	char	*str;

	str = ft_strsub(s, *strt - s, *nd - *strt);
	*strt = NULL;
	*nd = NULL;
	return (str);
}

static char	**ft_clear(char **s)
{
	char **str;

	str = s;
	while (*str)
		ft_strdel(str++);
	ft_strdel(s);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	*strt;
	char	*nd;
	char	**str;
	int		j;

	strt = NULL;
	nd = NULL;
	i = -1;
	j = 0;
	if (!s || !(str = (char **)malloc(sizeof(str) * (wordscnt(s, c) + 1))))
		return (NULL);
	while (*(s + ++i))
	{
		ft_getwordptr(s + i, c, &strt, &nd);
		if (strt && nd)
			if (!(str[j++] = ft_getword(s, &strt, &nd)))
				return (ft_clear(str));
	}
	str[j] = NULL;
	return (str);
}
