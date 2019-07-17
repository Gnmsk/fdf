#include "fdf.h"

int		fdf_read(int fd, t_okno window, t_stroka **argv_postrochno)
{
    char	*argv;
	int		str_quantity;
	char	**splitted_argv;
	t_stroka	*tmp;

	str_quantity = 0;
    while (get_next_line(fd, &argv))
	{
		if (!(splitted_argv = ft_strsplit(argv, ' ')))
	 		pizdec('b');
		if (str_quantity == 0)
			tmp = stroka_new(splitted_argv);
		else
			stroka_push_front(&tmp, splitted_argv);
		str_quantity++;
	}
	stroka_reverse(&tmp);
	*argv_postrochno = tmp;
	ft_strdel(&argv);
	return (str_quantity);
}
