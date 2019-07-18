/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:18:33 by tkelsie           #+#    #+#             */
/*   Updated: 2019/07/18 14:58:47 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 20
# define WIDTH 2560
# define HIGHT 1440
# define NAME "fdf"


# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

typedef struct		s_gnllist
{
	int					fd;
	char				*data;
	struct s_gnllist	*next;
}					t_gnllist;

typedef	struct		s_point
{
	int	x;
	int	y;
	int	z;
	int color;
}					t_point;

typedef struct		s_okno
{
	void *discriptor;
	void *win;
}					t_okno;

typedef	struct		s_stroka
{
	char			**data;
	struct s_stroka *next;
}					t_stroka;

typedef	struct		s_megastructura
{
	int kotoriy_jdet_svoego_chasa;
}					t_megastructura;

int					get_next_line(const int fd, char **line);
int					fdf_read(int fd, t_okno window, t_stroka **argv_postrochno);
void				split_argv(char *argv, t_okno window);
void				pizdec(char i);
void				zbs(void);
t_stroka			*stroka_new(char **content);
void				stroka_push_front(t_stroka **list, char **data);
void				stroka_reverse(t_stroka **begin_list);
int					keyboard(int key);
int					*fdf_cords_int(t_stroka *argv_postrochno, int size);
char				*fdf_cords_color(t_stroka *tmp, int size);

#endif
