/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_initialize_board.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/11 19:14:21 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/11 19:14:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				initialize_board(uint16_t **board)
{
	size_t			i;

	i = 0;
	*board = (uint16_t *)malloc(sizeof(uint16_t) * 16);
	while (i < 16)
	{
		(*board)[i] = (uint16_t)malloc(sizeof(uint16_t) * 1);
		(*board)[i] = 0;
		//printf("board[%lu] = %d \n", i, board[i]);
		i++;
	}
}

int					square_root(int num)
{
	int				temp;
	int				res;

	temp = 0;
	res = 0;
	while (res <= num)
	{
		res = temp * temp;
		//printf("\n temp = %d", temp);
		if (res == num)
			return (temp);
		temp++;
	}
	temp--;
	return (temp);
}

int					initial_boardsize(t_list *tetr_lst)
{
	int				size;

	size = ft_lstlen(tetr_lst);
	//printf("\n no of tet = %d", size);
	size = square_root(size * 4);
	//printf("\n size = %d", size);
	return (size);
}
