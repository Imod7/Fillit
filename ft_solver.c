/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solver.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:27:35 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/27 18:20:59 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					place_tetrimino(t_tetlst *tetlst, uint16_t **board, size_t row, size_t col)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	tetlst->row = row;
	tetlst->col = col;
    // iterate through all the bits of the tetrimino
	while (tetrow < 4)
	{
		tetbit = (tetlst->tet << col) >> (tetrow * 16);
		(*board)[row] |= tetbit;
		tetrow++;
		row++;
	}
	return (0);
}

int					remove_tetrimino(t_tetlst *tetlst, uint16_t **board)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	// iterate through all the bits of the tetrimino
	while (tetrow < 4)
	{
		tetbit = (tetlst->tet << tetlst->col) >> (tetrow * 16);
		(*board)[tetlst->row + tetrow] &= ~tetbit;
		tetrow++;
	}
	return (0);
}

int					can_be_placed(t_tetlst *tetlst, uint16_t **board, size_t size)
{
	uint16_t		tetbit;
	size_t			tetrow;
	uint16_t		size_limit;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (tetlst->tet << tetlst->col) >> (tetrow * 16);
		if (!tetbit)
			break;
		size_limit = ((*board)[tetlst->row + tetrow] | tetbit);
		if ((size_limit >> size) != 0)
			return (1);
		if (tetlst->row + tetrow > size - 1)
			return (1);
		if ((((*board)[tetlst->row + tetrow] & tetbit) != 0) || (tetlst->row + tetrow > (size - 1)))
			return (1);
		tetrow++;
	}
	return (0);
}

int					fill_board(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	uint64_t		tet;

	tet = tetr_lst->tet;
	tetr_lst->row = 0;
	while (tetr_lst->row < size)
	{
		tetr_lst->col = 0;
		while (tetr_lst->col < size)
		{
			if (can_be_placed(tetr_lst, board, size) == 0)
			{
				printf(ANSI_COLOR_GREEN "   It is safe to place the tetrimino \n" ANSI_COLOR_RESET);
				place_tetrimino(tetr_lst, board);
				if (fill_board(tetr_lst, board, size) == 1 || checklst(tetr_lst) == 1)
				{
					printf("   RECURSION Run Successfully for tet %llu @ (%lu, %lu)\n", tetr_lst->tet, tetr_lst->row, tetr_lst->col);
					return (1);
				}
				printf(ANSI_COLOR_RED "   Removing the tetrimino \n" ANSI_COLOR_RESET);
				remove_tetrimino(tetr_lst, board);
			}
			else
				printf(ANSI_COLOR_RED "            Cannot be placed in board[%zu][%zu], size = %lu \n" ANSI_COLOR_RESET, tetr_lst->row, tetr_lst->col, size);
			tetr_lst->col++;
		}
		tetr_lst->row++;
	}
	if (tetr_lst->next = NULL)
		return (-1);
	return (0);
}

int					solver(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	while (size < 16)
	{
		ret = fill_board(tetr_lst, board, size);
		while (ret == -1)
			
		if (ret == 0)
		    size++;
		else
		    break ;
	}
	return (0);
}
