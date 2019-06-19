/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:38:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/19 17:14:18 by ravan-de      ########   odam.nl         */
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

uint64_t			*lst2arr(t_list *lst)
{
	uint64_t	*tets;
	int			tetcount;

	tets = (uint64_t *)malloc(sizeof(uint64_t) * 26);
	tetcount = 0;
	while (lst->next != NULL)
	{
		tets[tetcount] = *(uint64_t *)(lst->content);
		lst = lst->next;
		tetcount++;
	}
	tets[tetcount] = *(uint64_t *)(lst->content);
	tets[tetcount + 1] = 0;
	return (tets);
}

int	ft_lstlen(t_list *lst)
{
	int len;

	len = 1;
	while (lst->next != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void				ft_create_board(t_board *board)
{
	t_board			strip_1;
	t_board			strip_2;
	t_board			strip_3;
	t_board			strip_4;

	strip_1.state = 0;
	strip_1.tet = 0;
	strip_2.state = 0;
	strip_2.tet = 0;
	strip_3.state = 0;
	strip_3.tet = 0;
	strip_4.state = 0;
	strip_4.tet = 0;
	board[0] = strip_1;
	board[1] = strip_2;
	board[2] = strip_3;
	board[3] = strip_4;
}

int					main(int argc, char **argv)
{
	t_board			*board;
	int				strip_index;
	int				fd;
	t_list			*tetr_lst;
	int				output;
	int				map_size;
	unsigned short	square;

	strip_index = 0;
	board = (t_board *)malloc(4 * sizeof(t_board));
	ft_create_board(board);
	ft_putnbr(board[3].tet);
	square = 0;
	map_size = 2;
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
		print_board(board);
		while (map_size * map_size < 4 * ft_lstlen(tetr_lst))
			map_size++;
		while (square == 0 && map_size < 16)
		{
			ft_putnbr(map_size);
			ft_putendl(" map_size");
			square = ft_recursive(board, map_size, lst2arr(tetr_lst), 0);
			map_size++;
		}
		close(fd);
	}
	return (0);
}
