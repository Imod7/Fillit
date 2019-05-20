/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 14:44:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/05/20 15:55:47 by dsaripap      ########   odam.nl         */
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

	//printf(" Tetrimino as short %d \n", num);
	tetrm = ft_lstnew(&num, 16);
	ft_lstaddend(tetr_lst, tetrm);
}

void				place_tetriminos(t_list **tetr_lst)
{
	t_list			*temp;

	temp = *tetr_lst;
	printf("1st tetr = %d\n", *(unsigned short *)(temp->content));
	*(unsigned short *)(temp->content) = *(unsigned short *)(temp->content) << 3;
	printf("1st tetr shifted on 1st position= %d\n", *(unsigned short *)(temp->content));
}

int					read_tetriminos(int fd, char *argv, t_list **tetr_lst)
{
	int 			bytes_read;
	char			buf[2];
	size_t 			row;
	size_t			column;
	unsigned short 	num;
	unsigned short	pos;
	int			m;
	char 			*tetr_char;

	pos = 32768;
	num = 0;
	bytes_read = 2;
	tetr_char = (char *)malloc(sizeof(char)*16);
	while (bytes_read > 0 && bytes_read != 1)
	{
		//m = 0;
		row = 0;
		while (row < 4)
		{
			column = 0;
			while (column < 4)
			{
				bytes_read = read(fd,buf,1);
				if (bytes_read == -1)
					return (-1);
				if (*buf == '.')
					tetr_char[m] = '0';
				else if (*buf == '#')
				{
					num = num + pos;
					tetr_char[m] = '1';
				}
				pos = pos / 2;
				column++;
				printf(" tetr[%d]=%c \n", m, tetr_char[m]);
				m++;
			}
			if (row == 3)
			{
				printf(" result string= %s \n saving as short %d in node \n", tetr_char, num);
				printf("\n\n");
				save_tolist(tetr_lst, num);
				bytes_read = read(fd,buf,2);
				pos = 32768;
				num = 0;
			}
			else
			{
				printf("\n");
				bytes_read = read(fd,buf,1);
			}
			row++;
		}
	}
	return (0);
}

void				print_list(t_list **tetr_lst)
{
	t_list 			*temp;
	size_t			i;

	i = 1;
	printf("\n=== Printing Linked List with Tetriminos ===\n");
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
		read_tetriminos(fd, argv[1], &tetr_lst);
		print_list(&tetr_lst);
		place_tetriminos(&tetr_lst);
		close(fd);
	}
}
