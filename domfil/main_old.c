/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 14:44:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/05/25 13:23:56 by dsaripap      ########   odam.nl         */
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

int					check_neighbours()
{
	return (0);	
}

int					read_newlines(int fd, char *buf)
{
	int				bytes_read;

	bytes_read = read(fd, buf, 1);
	//Checking that at the end of every tetrimino I have a newline
	//eg. for the first tetrimino its the 16th position
	if (*buf != '\n')
		return (-1);
	bytes_read = read(fd, buf, 1);
	//Checking that between every tetrimino I have a newline
	if (*buf != '\n')
		return (-1);
	return (bytes_read);
}

int					read_line(int fd, unsigned short *n, size_t pos)
{
	size_t			column;
	char			buf[2];
	int				bytes_read;

	column = 0;
	while (column < 4)
	{
		//Reading every character in eeach line (for the first 3 lines)
		//The 4th line is not read in this loop
		bytes_read = read(fd, buf, 1);
		if (bytes_read == -1 || (*buf != '.' && *buf != '#'))
			return (-1);
		if (*buf == '#')
			*n |= 1 << pos;
		pos++;
		column++;
	}
	return (pos);
}

int					read_file(int fd, t_list **tetr_lst)
{
	int				bytes_read;
	unsigned short	num;
	char			buf[2];
	size_t			row;
	size_t			pos;

	bytes_read = 1;
	while (bytes_read == 1)
	{
		pos = 0;
		row = 0;
		num = 0;	
		//Reading the first 3 lines of every tetrimino
		while (row < 3)
		{
			row++;
			pos = read_line(fd, &num, pos);
			bytes_read = read(fd, buf, 1);
			printf("bytes_read = %d", bytes_read);
		}
		
		//Reading the 4th line of every tetrimino
		pos = read_line(fd, &num, pos);
		save_tolist(tetr_lst, num);
		bytes_read = read_newlines(fd, buf);
		if (bytes_read == -1)
			return (-1);
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
		printf("node %lu -> %d \n", i, *(unsigned short *)(temp->content));
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
	int				output;

	if (print_usage(argc) == 0)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		tetr_lst = NULL;
		output = read_file(fd, &tetr_lst);
		if (output == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else
			print_list(&tetr_lst);
		//place_tetriminos(&tetr_lst);
		close(fd);
	}
	return (0);
}
