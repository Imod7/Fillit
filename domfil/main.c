/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 14:44:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/05/20 21:41:01 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void				save_tolist(t_list **tetr_lst, unsigned short num)
{
	t_list			*tetrm;

	tetrm = ft_lstnew(&num, 16);
	ft_lstaddend(tetr_lst, tetrm);
}

void				place_tetriminos(t_list **tetr_lst)
{
	t_list			*temp;
	int				x;

	x = 2;
	x = x << 3;
	printf("x = %d\n", x);
	temp = *tetr_lst;
	printf("1st tetr = %d\n", *(unsigned short *)(temp->content));
}

int					read_line(int fd, unsigned short *n, int bytes, size_t pos)
{
	size_t			column;
	char			buf[2];

	column = 0;
	while (column < 4)
	{
		bytes = read(fd, buf, 1);
		if (bytes == -1)
			return (-1);
		if (*buf == '#')
			*n |= 1 << pos;
		pos++;
		column++;
	}
	return (pos);
}

int					read_file(int fd, char *argv, t_list **tetr_lst)
{
	int				bytes_read;
	unsigned short	num;
	char			buf[2];
	size_t			row;
	size_t			pos;

	bytes_read = 2;
	while (bytes_read > 0 && bytes_read != 1)
	{
		pos = 0;
		row = 0;
		num = 0;
		while (row < 3)
		{
			row++;
			pos = read_line(fd, &num, bytes_read, pos);
			bytes_read = read(fd, buf, 1);
		}
		pos = read_line(fd, &num, bytes_read, pos);
		save_tolist(tetr_lst, num);
		bytes_read = read(fd, buf, 2);
	}
	return (0);
}

void				print_list(t_list **tetr_lst)
{
	t_list			*temp;
	size_t			i;

	i = 1;
	printf("\n=== Printing Linked List with Tetriminos ===\n\n");
	temp = *tetr_lst;
	while (temp != NULL)
	{
		printf("node %zu -> %d \n", i, *(unsigned short *)(temp->content));
		temp = temp->next;
		i++;
	}
}

int					print_usage(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_list			*tetr_lst;
	t_list			*map;

	if (print_usage(argc) == 0)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		tetr_lst = NULL;
		read_file(fd, argv[1], &tetr_lst);
		print_list(&tetr_lst);
		//place_tetriminos(&tetr_lst);
		close(fd);
	}
}
