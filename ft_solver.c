/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solver.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:27:35 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/04 22:05:08 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"	

int			place_tetrimino(t_tetlst *tetlst, uint16_t **board)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (uint16_t)((tetlst->tet << tetlst->col) >> (tetrow * 16));
		(*board)[tetlst->row + tetrow] |= tetbit;
		tetrow++;
	}
	tetlst->placed = 1;
	return (0);
}

int			remove_tetrimino(t_tetlst *tetlst, uint16_t **board)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (uint16_t)((tetlst->tet << tetlst->col) >> (tetrow * 16));
		(*board)[tetlst->row + tetrow] &= ~tetbit;
		tetrow++;
	}
	tetlst->placed = 0;
	return (0);
}

int			can_be_placed(t_tetlst *tetlst, uint16_t **board, size_t size)
{
	uint16_t		tetbit;
	size_t			tetrow;
	uint16_t		size_limit;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (uint16_t)((tetlst->tet << tetlst->col) >> (tetrow * 16));
		if (!tetbit)
			break ;
		size_limit = (uint16_t)((*board)[tetlst->row + tetrow] | tetbit);
		if ((size_limit >> size) != 0)
			return (1);
		if ((tetlst->row + tetrow) > (size - 1))
			return (1);
		if (((*board)[tetlst->row + tetrow] & tetbit) != 0)
			return (1);
		tetrow++;
	}
	return (0);
}

int	check_end(t_tetlst	*tetr_lst)
{
	t_tetlst	*temp;

	temp = tetr_lst;
	while (temp->placed == 1)
	{
		temp = temp->next;
		if (temp == NULL)
			return (1);
	}
	return (0);
}

int			lstcmp(uint64_t tet, uint64_t *prevlst)
{
	size_t lst_index;

	lst_index = 0;
	while(prevlst[lst_index] != 0)
	{
		if (tet == prevlst[lst_index])
			return (1);
		lst_index++;
	}
	prevlst[lst_index] = tet;
	return (0);
}

int			fill_board(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	t_tetlst	*prevtet;
	uint64_t	*prevlst;
	t_tetlst	*newtet;

	prevlst = malloc(sizeof(uint64_t) * (tetlstlen(tetr_lst) + 1));
	ft_bzero(prevlst, sizeof(uint64_t) * (tetlstlen(tetr_lst) + 1));
	newtet = tetr_lst;
	prevtet = NULL;
	while (newtet->placed == 1)
	{
		newtet = newtet->next;
		if (newtet == NULL)
		{
			free(prevlst);
			return (1);
		}
	}
	newtet->row = 0;
	while (newtet->row < size)
	{
		newtet->col = 0;
		while (newtet->col < size)
		{
			if (can_be_placed(newtet, board, size) == 0)
			{
				place_tetrimino(newtet, board);
				lstcmp(newtet->tet, prevlst);
				if (fill_board(tetr_lst, board, size) == 1)
				{
					free(prevlst);
					return (1);
				}
				prevtet = newtet;
				remove_tetrimino(prevtet, board);
				while (lstcmp(newtet->tet, prevlst) == 1)
				{
					newtet = newtet->next;
					if (newtet == NULL)
					{
						free(prevlst);
						return (0);
					}
					while (newtet->placed == 1)
					{
						newtet = newtet->next;
						if (newtet == NULL)
						{
							free(prevlst);
							return (0);
						}
					}
				}
				prevtet->row = 0;
				prevtet->col = 0;
			}
			else
				newtet->col++;
		}
		newtet->row++;
	}
	newtet->row = 0;
	newtet->col = 0;
	free(prevlst);
	return (0);
}

int			solver(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	while (size < 16)
	{
		if (fill_board(tetr_lst, board, size) == 0)
			size++;
		else
			break ;
	}
	return (size);
}
