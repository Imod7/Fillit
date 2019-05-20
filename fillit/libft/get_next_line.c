/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 15:03:15 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/29 17:44:20 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <stdlib.h>

static int	ft_locatefd(char *rest, int fd)
{
	size_t	n;
	char	*itoa;

	n = 0;
	while (rest[n] != '\0')
	{
		if (ft_atoi(&rest[n]) == fd)
			return (n + FDL + 1);
		if (n >= (BUFF_SIZE + FDL + 2) * FDN)
			return (-1);
		n += BUFF_SIZE + FDL + 2;
	}
	itoa = ft_itoa(fd);
	if (itoa == NULL)
		return (-1);
	ft_strcpy(&rest[n], itoa);
	free(itoa);
	return (n + FDL + 1);
}

static int	ft_read(char **line, char *rest, int bytes_read, int fd)
{
	char	*buf;
	size_t	i;

	i = 0;
	if (ft_strlen(rest) == 0 || bytes_read == -2)
	{
		buf = (char *)ft_memalloc(BUFF_SIZE + 1);
		ft_bzero(rest, BUFF_SIZE);
		bytes_read = read(fd, (void *)buf, BUFF_SIZE);
		if (bytes_read <= 0)
			return (bytes_read);
		ft_memcpy(rest, buf, bytes_read);
		ft_strdel(&buf);
	}
	*line = ft_str_resize(*line, ft_strlen(*line) + ft_strlen(rest));
	if (*line == NULL)
		return (-1);
	if (ft_memccpy(ft_strchr(*line, '\0'), rest, '\n', ft_strlen(rest)) == NULL)
		return (-2);
	line[0][ft_strlen(*line) - 1] = '\0';
	while (rest[i] != '\n')
		i++;
	ft_memmove(rest, &rest[i + 1], ft_strlen(&rest[i + 1]) + 1);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		rest[(BUFF_SIZE + FDL + 2) * FDN];
	int				index;
	int				bytes_read;

	bytes_read = BUFF_SIZE;
	index = ft_locatefd(rest, fd);
	rest[index + BUFF_SIZE] = '\0';
	if (index == -1 || line == NULL)
		return (-1);
	*line = ft_strnew(0);
	while (bytes_read != 0)
	{
		bytes_read = ft_read(line, &rest[index], bytes_read, fd);
		if (bytes_read == 1 || bytes_read == -1)
			return (bytes_read);
	}
	if (ft_strlen(*line) == 0)
		return (0);
	return (1);
}
