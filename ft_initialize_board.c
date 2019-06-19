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

void				initialize_board(unsigned short **board)
{
	size_t			i;

	i = 0;
	*board = (unsigned short *)malloc(sizeof(unsigned short) * 16);
	while (i < 16)
	{
		(*board)[i] = (unsigned short)malloc(sizeof(unsigned short) * 1);
		(*board)[i] = 0;
		//printf("board[%lu] = %d \n", i, board[i]);
		i++;
	}
}
