/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_solver.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 18:27:35 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/09 19:48:39 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"	

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

int			place_tetrimino(t_tetlst *tetlst, uint16_t **board, uint64_t *prevlst)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (uint16_t)((uint64_t)(tetlst->tet << tetlst->col) >> (tetrow * 16));
		(*board)[tetlst->row + tetrow] |= tetbit;
		tetrow++;
	}
	lstcmp(tetlst->tet, prevlst);
	tetlst->placed = 1;
	ft_putendl("placed:");
	printlst(tetlst);
	ft_putendl("");
	return (0);
}

int			remove_tetrimino(t_tetlst *tetlst, uint16_t **board)
{
	uint16_t		tetbit;
	size_t			tetrow;

	tetrow = 0;
	while (tetrow < 4)
	{
		tetbit = (uint16_t)((uint64_t)(tetlst->tet << tetlst->col) >> (tetrow * 16));
		(*board)[tetlst->row + tetrow] &= ~tetbit;
		tetrow++;
	}
	tetlst->placed = 0;
	tetlst->col = 0;
	tetlst->row = 0;
	ft_putendl("removed:");
	printlst(tetlst);
	ft_putendl("");
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
		tetbit = (uint16_t)((uint64_t)(tetlst->tet << tetlst->col) >> (tetrow * 16));
		if (!tetbit)
			break ;
		size_limit = ((*board)[tetlst->row + tetrow] | tetbit);
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

t_tetlst	*replace(t_tetlst *tetr_lst, t_tetlst *tet, uint16_t **board, uint64_t *prevlst)
{
	t_tetlst	*newtet;

	remove_tetrimino(tet, board);
	newtet = tetr_lst;
	while (lstcmp(newtet->tet, prevlst) == 1 || newtet->placed == 1)
	{
		newtet = newtet->next;
		if (newtet == NULL)
		{
			free(prevlst);
			return (NULL);
		}
	}
	return (newtet);
}

int			move_tet(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	uint64_t	*prevlst;
	t_tetlst	*newtet;

	prevlst = malloc(sizeof(uint64_t) * (tetlstlen(tetr_lst) + 1));
	ft_bzero(prevlst, sizeof(uint64_t) * (tetlstlen(tetr_lst) + 1));

	newtet = tetr_lst;
	while (newtet->placed == 1)
	{
		newtet = newtet->next;
		if (newtet == NULL)
		{
			free(prevlst);
			return (0);
		}
	}
	while (newtet != NULL)
	{
		newtet->col = 0;
		while (newtet->col < size)
		{
			if (can_be_placed(newtet, board, size) == 0)
			{
				place_tetrimino(newtet, board, prevlst);
				ft_putendl("Board state:");
				ft_printboard(tetr_lst, size);
				ft_putendl("\n");
				if (move_tet(tetr_lst, board, size) == 1)
				{
					newtet = replace(tetr_lst, newtet, board, prevlst);
					if (newtet == NULL)
						return (1);
				}
				else
				{
					free(prevlst);
					return (0);
				}
				ft_putendl("Board state:");
				ft_printboard(tetr_lst, size);
				ft_putendl("\n");
			}
			else
				newtet->col++;
		}
		newtet->row++;
		if (newtet->row == 16)
		{
			newtet->row = 0;
			newtet->col = 0;
			newtet = newtet->next;
		}
	}
	free(prevlst);
	return (1);
}

int			fill_board(t_tetlst *tetr_lst, uint16_t **board, size_t size)
{
	int			ret;

	ret = 1;
	while (ret == 1 && size < 16)
	{
		ret = move_tet(tetr_lst, board, size);
		if (ret == 1)
			size++;
		if (size == 5)
			return (size);
	}
	return (size);
}
