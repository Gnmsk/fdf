int		*fdf_cords_int(t_stroka *tmp, int size)
{
	int			*cords;
	int			i;
	int			k;

	if (!(cords = (int *)malloc(sizeof(int) * size)))
		pizdec('d');
	k = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->data[i])
		{
			cords[k++] = ft_atoi(tmp->data[i++]);
			printf("%d ", cords[k - 1]);
		}
		printf("\n");
		tmp = tmp->next;
	}
	printf("\n");
	return (cords);
}

char	*fdf_cords_color(t_stroka *tmp, int size)
{
	char		*cords;
	int			i;
	int			k;

	if (!(cords = ft_strnew(size + 1)))
		pizdec('d');
	k = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->data[i])
		{
			cords[k++] = (ft_atoi(tmp->data[i++]) > 0) ? 'r' : 'w';
			printf("%c ", cords[k - 1]);
		}
		printf("\n");
		tmp = tmp->next;
	}
	cords[k] = '\0';
	printf("\n");
	return (cords);
}