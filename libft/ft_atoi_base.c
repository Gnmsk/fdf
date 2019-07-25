/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:46:37 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/25 15:35:53 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb(char c, int base)
{
	int		result;

	if (c >= '0' && c <= '9')
		result = c - '0';
	else if (c >= 'a' && c <= 'z')
		result = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		result = c - 'A' + 10;
	else
		return (-1);
	return (result < base ? result : -1);
}

int				ft_atoi_base(char *nb, int base)
{
	int		res;
	int		length;
	int		sign;

	if (base == 10)
		return (ft_atoi(nb));
	while (*nb == ' ' || *nb == '\t' || *nb == '\n'
			|| *nb == '\v' || *nb == '\r' || *nb == '\f')
		nb++;
	sign = (*nb == '-' ? -1 : 1);
	nb = (*nb == '-' || *nb == '+') ? nb + 1 : nb;
	if (base == 16 && *nb == '0' && (*(nb + 1) == 'x'
				|| *(nb + 1) == 'X'))
		nb += 2;
	res = 0;
	length = ft_strlen(nb) - 1;
	while (*nb && length >= 0 && ft_nb(*nb, base) != -1)
	{
		res += ft_nb(*nb, base) * ft_pow(base, length);
		nb++;
		length--;
	}
	return (res * sign);
}
