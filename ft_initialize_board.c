/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialize_board.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 19:14:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/07/04 17:32:27 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	square_root(int num)
{
	int	temp;
	int	res;

	temp = 0;
	res = 0;
	while (res <= num)
	{
		res = temp * temp;
		if (res == num)
			return (temp);
		temp++;
	}
	temp--;
	return (temp);
}

int	tetlstlen(t_tetlst *tetr_lst)
{
	size_t count;

	count = 0;
	while (tetr_lst != NULL)
	{
		count++;
		tetr_lst = tetr_lst->next;
	}
	return (count);
}

int	initial_boardsize(t_tetlst *tetr_lst)
{
	size_t	size;

	size = tetlstlen(tetr_lst);
	size = square_root(size * 4);
	return (size);
}

int	initialize_board(uint16_t **board, t_tetlst *tetr_lst)
{
	size_t	i;

	i = 0;
	*board = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	while (i < 16)
	{
		(*board)[i] = 0;
		i++;
	}
	return (initial_boardsize(tetr_lst));
}
