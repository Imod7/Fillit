/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:46:58 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/27 15:09:49 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void				print_board(unsigned short *board)
{
	int				bit;
	int				row;
	unsigned short	mask;

	bit = 0;
	//printf("board[%d] = %d \n", 22, board[22]);
	row = 0;
	while (row < 16)
	{
		bit = 0;
		//printf("board[%d] = %d \n", row, board[row]);
		while (bit < 16)
		{
			
			mask = board[row] >> bit;
			//printf("bit = %d , mask = %d , -- %d \n", bit, mask, mask & 1);
			if (mask & 1)
				printf("1 ");
			else
				printf("0 ");
			bit++;
		}
		row++;
		printf("\n");
	}
}

void				print_binary(uint64_t num, int size)
{
	int				bit;
	int				row;
	int 			col;
	uint64_t		mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < (size * size))
		{
			mask = num >> bit;
			//printf("\n mask = %llu \n", mask);
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

void				print_binary_orig(unsigned short num, int size)
{
	int				bit;
	int				row;
	int 			col;
	unsigned short	mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
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

void				print_binary_d(uint64_t num, int size)
{
	int				bit;
	int				row;
	int 			col;
	unsigned short	mask;

	bit = 0;
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
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

void				print_list(t_tetlst *tetr_lst)
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
