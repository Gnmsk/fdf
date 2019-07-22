#include "fdf.h"

void	draw(t_mega megastruct)
{
	int i;

	while (megastruct.coords[i])
	{
		if (megastruct.cords[i].x < megastruct.coords_in_x_quantity):
			draw_line(megastruct.coords[i], megastruct.coords[i + 1]);
		if (megastruct.cords[i + megastruct.coords_in_x_quantity]):
			draw_line(megastruct.coords[i],megastruct.coords[i + megastruct.coords_in_x_quantity]);
		i++;
	}
}

{	
	if	((b.x - a.x) && ((b.x - a.x) >= (b.y - a.y)) && (b.y - a.y)) //все ок
		return (1);
	if	(((b.x - a.x) < (b.y - a.y)) && (b.y - a.y)) // больше 45
 		return (2);
	if	((b.x - a.x) && ((b.x - a.x) >= (a.y - b.y)) && (b.y < a.y)) // меньше 45 но вниз
		return (3);
	if	((b.y < a.y) && ((a.y - b.y) > (b.x - a.x))) // больше 45 и вниз
		return (4);
	else
		printf("var detect error");
}

int	find_point_in_million(t_point xyz, int	max_x)
{
	int i;

	i = xyz.y * max_x + xyz.x;
	return (i);
}

void	draw_line(int x1, int y1, int x2, int y2, int var)
{
	float angle;
	float y_error;
	float x_error;
	
	y_error = 0;
	x_error = 0;
}