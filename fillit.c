/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:38:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/31 15:34:46 by ravan-de      ########   odam.nl         */
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

unsigned short		*lst2arr(t_list *lst)
{
	unsigned short	*tets;
	int				tetcount;

	tets = (unsigned short *)malloc(sizeof(unsigned short) * 26);
	tetcount = 0;
	while (lst->next != NULL)
	{
		tets[tetcount] = (unsigned short)(lst->content);
		lst = lst->next;
		tetcount++;
	}
	tets[tetcount + 1] = (unsigned short)(lst->content);
	tets[tetcount + 2] = 0;
	return (tets);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_list			*tetr_lst;
	int				output;
	unsigned short	square;

	square = 0;
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
		square = ft_recursive(0, 0, lst2arr(tetr_lst), 0);
		close(fd);
	}
	return (0);
}
