/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:38:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/26 20:35:22 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

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
	uint16_t		*board;
	t_tetlist		*tetr_lst;
	int				fd;
	size_t			size;

	board = NULL;
	tetr_lst = NULL;
	if (print_usage(argc) == 0)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		tetr_lst = NULL;
		if (read_file(fd, &tetr_lst) == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else
			print_list(&tetr_lst);
		size = initial_boardsize(tetr_lst);
		initialize_board(&board);
		solver(tetr_lst, &board, size);
		ft_letters(tetr_lst);
		close(fd);
	}
	return (0);
}
