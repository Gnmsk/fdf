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


// void	draw_line(int x1, int y1, int x2, int y2, int var)
// {
// 	float angle;
// 	float y_error;
// 	float x_error;
	
// 	y_error = 0;
// 	x_error = 0;
// }


// {	
// 	if	((b.x - a.x) && ((b.x - a.x) >= (b.y - a.y)) && (b.y - a.y)) //все ок
// 		draw_line(a.x, a.y, b.x, b.y);
// 		//return (1);
// 	if	(((b.x - a.x) < (b.y - a.y)) && (b.y - a.y)) // больше 45
// 	{
// 		draw_line(a.y, a.x, b.y, b.x);
// 	}
//  		//return (2);
// 	if	((b.x - a.x) && ((b.x - a.x) >= (a.y - b.y)) && (b.y < a.y)) // меньше 45 но вниз
// 	{
// 		draw_line(a.x, b.y, b.x, a.y);
// 	}
// 		//return (3);
// 	if	((b.y < a.y) && ((a.y - b.y) > (b.x - a.x))) // больше 45 и вниз
// 		draw_line(a.x, b.x, b.y, a.y);
// 		//return (4);
// 	else
// 		printf("var detect error");
// }
