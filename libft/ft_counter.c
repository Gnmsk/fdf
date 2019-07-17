#include "libft.h"

int		counter(char *s, int ch)
{
	int		nb;
	char	*str;

	nb = 0;
	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == ch)
			nb++;
		str++;
	}
	return (nb);
}