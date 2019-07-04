/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:38:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/04 22:05:47 by ravan-de      ########   odam.nl         */
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
	t_tetlst		*tetr_lst;
	int				fd;
	size_t			size;

	board = NULL;
	tetr_lst = NULL;
	if (print_usage(argc) == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	if (read_file(fd, &tetr_lst) == -1)
	{
		write(2, "error\n", 6);
		return (0);
	}
	print_list(tetr_lst);
	size = initialize_board(&board, tetr_lst);
	size = solver(tetr_lst, &board, size);
	ft_putendl("");
	ft_printboard(tetr_lst, size);
	ft_free(tetr_lst, &board);
	close(fd);
	return (0);
}
