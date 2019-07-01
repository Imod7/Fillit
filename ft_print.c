/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:46:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/01 15:24:59 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	print_binary(uint64_t num, int size)
{
	int			bit;
	int			row;
	int			col;
	uint64_t	mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < (size * size))
		{
			mask = num >> bit;
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
			col++;
		}
		row++;
		printf("\n");
	}
}

void	print_list(t_tetlst *tetr_lst)
{
	size_t			i;

	i = 1;
	printf(ANSI_COLOR_CYAN "\n=== Printing Linked List of Tetriminos ===\n" ANSI_COLOR_RESET);
	while (tetr_lst != NULL)
	{
		printf(" tetr/node %lu -> %llu \n", i, tetr_lst->tet);
		tetr_lst = tetr_lst->next;
		i++;
	}
	ft_putnbr(i);
}
