/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solver.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:27:35 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/26 18:27:39 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					place_tetrimino(uint64_t tet, uint16_t **board, size_t size, size_t row, size_t col, int check)
{
	uint16_t		tetbit;
	uint64_t		tetshift;
	size_t			tetrow;
	size_t			last_pos;

	check = 0;
	tetrow = 0;
	last_pos = 0;
	(void)size;
    // iterate through all the bits of the tetrimino
	while (tetrow < 4)
	{
		tetshift = tet << col;
		tetshift = tetshift >> (tetrow * 16);
		tetbit = (uint16_t)tetshift;
		(*board)[row] |= tetbit;
		tetrow++;
		row++;
	}
	return (0);
}

int					remove_tetrimino(uint64_t tet, uint16_t **board, size_t size, size_t row, size_t col, int check)
{
	uint16_t		tetbit;
	uint64_t		tetshift;
	size_t			tetrow;
	size_t			last_pos;

	check = 0;
	tetrow = 0;
	last_pos = 0;
	(void)size;
	// iterate through all the bits of the tetrimino
	while (tetrow < 4)
	{
		tetshift = tet << col;
		tetshift = tetshift >> (tetrow * 16);
		tetbit = (uint16_t)tetshift;
		(*board)[row] &= ~(tetbit);
		tetrow++;
		row++;
	}
	return (0);
}

int					can_be_placed(uint64_t tet, uint16_t **board, size_t size, size_t row, size_t col, int check)
{
	uint16_t		tetbit;
	uint64_t		tetshift;
	size_t			tetrow;
	// size_t			b_pos;
	size_t			last_pos;
	uint16_t		size_limit;
	uint16_t 		rightset_bit;

	check = 0;
	tetrow = 0;
	last_pos = 0;
	//size = 0;
	rightset_bit = 0;
	// iterate through all the bits of the tetrimino
	while (tetrow < 4)
	{
		tetshift = tet << col;
		tetshift = tetshift >> (tetrow * 16);
		tetbit = (uint16_t)tetshift;
		if (!tetbit)
			break;
		//checking if it goes beyond the size limit
		size_limit = ((*board)[row] | tetbit);
		if (size == 8 && col == 0 && row == 2 && tet == 196611)
			{
			
			printf(ANSI_COLOR_MAGENTA "Current State of the board \n" ANSI_COLOR_RESET);
			print_board(*board);

			}
		if ((((*board)[row] & tetbit) != 0) || ((size_limit >> (size)) != 0) || (row > (size - 1)))
		{
			printf(ANSI_COLOR_RED "            Cannot be placed in board[%zu][%zu], size = %lu \n" ANSI_COLOR_RESET, row, col, size);
			return (1);
		}
		tetrow++;
		row++;
	}
	return (0);
}

int					fill_board(t_list *tetr_lst, uint16_t **board, size_t size)
{
	t_list			*temp;
	uint64_t		tet;
	size_t			row;
	size_t			col;

	temp = tetr_lst;
	row = 0;
	col = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			tet = *(uint64_t *)(temp->content);
			if ( (can_be_placed(tet, board, size, row, col , 1) == 0))
			{
				printf(ANSI_COLOR_GREEN "   It is safe to place the tetrimino \n" ANSI_COLOR_RESET);
				place_tetrimino(tet, board, size, row, col, 0);
				if ((temp->next == NULL) || (fill_board(tetr_lst->next, board, size) == 1))
				{
					printf("   RECURSION Run Successfully for tet %llu @ (%lu, %lu)\n", *(uint64_t *)(temp->content), row, col);
					return (1);
				}
				printf(ANSI_COLOR_RED "   Removing the tetrimino \n" ANSI_COLOR_RESET);
				remove_tetrimino(tet, board, size, row, col, 0);
			}
			col++;
		}
		row++;
	}
	return (0);
}

int					solver(t_list *tetr_lst, uint16_t **board, size_t size)
{
	while (size < 16)
	{
		if (fill_board(tetr_lst, board, size) == 0)
		    size++;
		else
		    break ;
	}
	return (0);
}