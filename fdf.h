/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:18:33 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 10:51:31 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 20
# define WIDTH 800
# define HIGHT 800
# define NAME "fdf"
# define ISO 30

# define STARTCOLOR 0x0F00F0F
# define ENDCOLOR 0xFCF75F

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef	struct		s_point
{
	int	x;
	int	y;
	int	z;
	int color;
}					t_point;

typedef struct		s_line
{
	t_point			a;
	t_point			b;
	struct s_line	*next;
}					t_line;

typedef	struct		s_stroka
{
	char			**data;
	struct s_stroka *next;
}					t_stroka;

typedef	struct		s_mega
{
	int					fd;
	void				*discriptor;
	void				*win;
	t_point				**coords;
	t_point				**iso_coords;
	int					max_x;
	int					max_y;
	t_point				min_max_z;
	int					max_;
	t_point				offset;
	int					zoom;
	void				*img;
	unsigned int		*data_adress;
	int					bits_per_pixel;
	int					size_line;
	int					endian;

}					t_mega;

int					get_next_line(const int fd, char **line);
void				fdf_read(t_mega *megastruct);

int					keyboard(int key, t_mega *megastruct);
void				pizdec(char i);
void				zbs(void);

t_stroka			*stroka_new(char **content);
void				stroka_push_front(t_stroka **list, char **data);
void				stroka_reverse(t_stroka **begin_list);
t_point				**fdf_cords_point(t_stroka *tmp, t_mega *megastruct);
void				draw(t_mega *megastruct);
void				find_point_in_million(t_point cur, t_mega megastrct);
void				draw_line(t_point a, t_point b, t_mega megastruct);

void				fill_backgound(int color, t_mega *megastruct);
void				put_pixel(int x, int y, int color, t_mega *megastruct);

void				set_color(char *data, t_point *cord, int zoom);
int					color(int start, int end, double percentage);
double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					get_color(t_point cur, t_point st, t_point end, t_point d);
void				gradient(t_mega *megastruct);

void				iso(t_point *p, t_point *offset);
void				rotation(t_mega *megastruct);

void				shift_x(t_mega *megastruct, int step);
void				shift_y(t_mega *megastruct, int step);
void				zoom(t_mega *megastruct, int key);

void				interface(t_mega *megastructura);
#endif
