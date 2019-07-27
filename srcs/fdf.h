/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:18:33 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/27 21:16:00 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 20

# define NAME "fdf"
# define WIDTH 1000
# define HIGHT 1000

# define DEFAULTZOOM 1
# define ISO 30

# define RED 0x0F00F0F
# define YELLOW 0xFCF75F

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
	int					size;
	int					proj;
	double				alpha;
	double				beta;
	double				gamma;
	t_point				offset;
	t_point				shift;
	int					zoom;
	void				*img;
	unsigned int		*data_adress;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}					t_mega;

void				valid(t_mega *megastruct);
void				valid_data(char *str);

t_stroka			*stroka_new(char **content);
void				stroka_push_front(t_stroka **list, char **data);
void				stroka_reverse(t_stroka **begin_list);

void				fdf_read(t_mega *megastruct);
t_point				**fdf_cords_point(t_stroka *tmp, t_mega *megastruct);
void				copy_point(t_point *d, t_point *s);
t_point				**copy_structure(t_mega *megastruct);

double				percent(int start, int end, int current);
int					get_light(int start, int end, double percentage);
int					color(int start, int end, double percentage);
int					get_color(t_point cur, t_point st, t_point end, t_point d);
void				set_color(char *data, t_point *cord, int zoom);
void				gradient(t_mega *megastruct);

void				rotation_x(t_point *p, t_mega *megastruct);
void				rotation_y(t_point *p, t_mega *megastruct);
void				rotation_z(t_point *p, t_mega *megastruct);
void				iso(t_point *p, t_point *offset);
void				rotation(t_mega *megastruct);

void				shift(t_mega *megastructura);
void				zoom(t_mega *megastruct, double zoom);
void				centre(t_mega *megastruct);
void				shift_xy(t_mega *megastruct, int step);
void				movements(int key, t_mega *megastruct);
void				zooming(int key, t_mega *megastruct);
void				projection(t_mega *megastruct);
void				default_state(t_mega *megastruct);

void				draw(t_mega *megastruct);
void				find_point_in_million(t_point cur, t_mega megastrct);
void				draw_line(t_point a, t_point b, t_mega megastruct);

void				interface(t_mega *megastructura);
void				display_map(t_mega *megastructura);
void				put_pixel(int x, int y, int color, t_mega *megastruct);
void				fill_backgound(int color, t_mega *megastruct);

int					keyboard(int key, t_mega *megastruct);
int					close_window(void *param);
void				pizdec(char i);
void				zbs(void);

#endif
