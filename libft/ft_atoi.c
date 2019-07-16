/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:32:44 by tkelsie           #+#    #+#             */
/*   Updated: 2019/04/19 20:15:02 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	res;
	long long	tmp;
	int			sign;

	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
	*str == '\n' || *str == '\f' || *str == '\r')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		tmp = res;
		res = res * 10 + *str++ - '0';
		if (tmp > res)
			return (sign == -1) ? 0 : -1;
	}
	return (sign * res);
}
