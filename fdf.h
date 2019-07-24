/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:18:33 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/24 19:42:57 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 20
# define WIDTH 800
# define HIGHT 800
# define NAME "fdf"

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

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
	int					coords_in_x_quantity;
	int					str_quantity;
	int					zoom;
	void				*img;
	unsigned int		*data_adress;
	int					bits_per_pixel;
	int					size_line;
	int					endian;

}					t_mega;

int					get_next_line(const int fd, char **line);
void				fdf_read(t_mega *megastruct);

int					keyboard(int key);
void				pizdec(char i);
void				zbs(void);

t_stroka			*stroka_new(char **content);
void				stroka_push_front(t_stroka **list, char **data);
void				stroka_reverse(t_stroka **begin_list);
t_point				**fdf_cords_point(t_stroka *tmp, int size, int zoom);
void				draw(t_mega *megastruct);
void				find_point_in_million(t_point cur, t_mega megastrct);
void				draw_line(t_point a, t_point b, t_mega megastruct);

double				percent(int start, int end, int current);
double				percentage(t_point d, t_point st, t_point end, t_point cur);
int					get_light(int start, int end, double percentage);
int					get_color(t_point cur, t_point st, t_point end, t_point d);

#endif
