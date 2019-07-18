/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelsie <tkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:08:57 by dbruen            #+#    #+#             */
/*   Updated: 2019/07/18 14:15:07 by tkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char		*get_line(char **curr_data)
{
	char	*res;
	char	*temp;
	size_t	i;

	i = 0;
	if (!(temp = ft_strdup(*curr_data)))
		return (NULL);
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strncpy(res, *curr_data, i);
	ft_strdel(curr_data);
	if (i < ft_strlen(temp))
	{
		if (!(*curr_data = ft_strdup(temp + i + 1)))
			return (NULL);
	}
	else
	{
		if (!(*curr_data = ft_strdup("\0")))
			return (NULL);
	}
	ft_strdel(&temp);
	return (res);
}

static	char		*ft_strjoinfree(char **curr_data, char *buf)
{
	char	*res;
	size_t	i;

	i = ft_strlen(*curr_data) + ft_strlen(buf);
	if (!(res = ft_strnew(i)))
		return (NULL);
	ft_strcpy(res, *curr_data);
	ft_strcat(res, buf);
	ft_strdel(curr_data);
	return (res);
}

static	t_gnllist	*find_fd(t_gnllist **mem_list, int fd)
{
	t_gnllist	*temp;

	temp = *mem_list;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_gnllist *)malloc(sizeof(t_gnllist))))
		return (NULL);
	if (!(temp->data = ft_strnew(0)))
		return (NULL);
	temp->fd = fd;
	temp->next = *mem_list;
	*mem_list = temp;
	return (temp);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnllist	*mem_list;
	t_gnllist			*curr;
	char				buf[BUFF_SIZE + 1];
	int					ret;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(curr = find_fd(&mem_list, fd)))
		return (-1);
	ret = 0;
	while (!(ft_strchr(curr->data, '\n')) &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(curr->data = ft_strjoinfree(&curr->data, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !(ft_strlen(curr->data)))
		return (0);
	if (!(*line = get_line(&curr->data)))
		return (-1);
	return (1);
}
