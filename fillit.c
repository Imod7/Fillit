/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:38:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/13 13:41:30 by ravan-de      ########   odam.nl         */
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

unsigned short		*lst2arr(t_list *lst)
{
	unsigned short	*tets;
	int				tetcount;

	tets = (unsigned short *)malloc(sizeof(unsigned short) * 26);
	tetcount = 0;
	while (lst->next != NULL)
	{
		tets[tetcount] = *(unsigned short *)(lst->content);
		lst = lst->next;
		tetcount++;
	}
	tets[tetcount] = *(unsigned short *)(lst->content);
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

int					main(int argc, char **argv)
{
	int				fd;
	t_list			*tetr_lst;
	int				output;
	int				map_size;
	unsigned short	square;

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
		while (map_size * map_size < 4 * ft_lstlen(tetr_lst))
			map_size++;
		while (square == 0 && map_size < 16)
		{
			ft_putnbr(map_size);
			ft_putendl(" map_size");
			square = ft_recursive(0, map_size, lst2arr(tetr_lst), 0);
			map_size++;
		}
		close(fd);
	}
	return (0);
}
