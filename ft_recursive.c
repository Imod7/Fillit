/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/19 20:48:41 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "fillit.h"

/*
	things that cause next tet:
		- tet created more holes than maxholes
		- tet goes over sepparator (after every 4 bits), no two 1 bits of the tet may be seperated by only the separator
		- shifting a 1 bit out of the tet
		- tet has been placed already (first and last bit of tet are 1)

	things that cause recursion:
		- none of the tets can be placed
*/

//all max_width represent the max map_size and will be set to 16
//all 32768's will be replaced with 9223372036854775807

//count set bits
//#define (max_width - map_size) jump to next line if end of board/map_size reached
int ft_countbit(unsigned short tet, int map_size)
{
	unsigned short i;
	int count;

	i = 1;
	count = 0;
	while (i <= max_width * max_width)
	{
		if (i % (map_size + 1) == 0 && i != 0)
			i += max_width - map_size;
		if ((1 << (i - 1) & tet) == 1 << (i - 1))
			count++;
		i++;
	}
	return (count);
}

int	ft_place(t_board strip, t_board strip_next, int map_size, uint64_t tet)
{
	int			offset;
	uint64_t	mask;
	uint64_t	max;

	max = 9223372036854775807;
	offset = 1;
	mask = 3 << (map_size - 1);
	if (strip.tet == 0)
		return (1);
	if ((mask & (strip.tet << offset)) == mask)
		return (0);
	while ((mask & (strip.tet << offset)) != mask && mask != 1 && mask != 0 && mask != max)
	{
		mask = mask << max_width;
	}
	if (mask != 1 && mask != 0 && mask != max)
	{
			offset += (max_width - offset % map_size) + (max_width - map_size);
			strip_next.tet = strip_next.tet << ((max_width - offset % map_size) + (max_width - map_size));
	}
	strip.tet = tet << offset;
	if ((strip.tet & ~strip.state) == strip.tet)
		return (1);
	else
		return (0);
}

int	ft_placer(t_board *board, int map_size, uint64_t tet)
{
	int ret;

	ret = 0;
	board[0].tet = tet;
	while (ret < 3)
	{
		ret = 0;
		ret += ft_place(board[0], board[1], map_size, board[0].tet);
		ret += ft_place(board[1], board[2], map_size, board[1].tet);
		ret += ft_place(board[2], board[3], map_size, board[2].tet);
		ret += ft_place(board[3], board[3], map_size, board[3].tet);
		ft_putnbr(ret);
		ft_putendl("");
		if (ft_countbit(board[3].tet, map_size) != 4 && board[2].tet == 0 && board[1].tet == 0 && board[0].tet == 0)
			return (0);
	}
	board[0].state |= board[0].tet;
	board[1].state |= board[1].tet;	
	board[2].state |= board[2].tet;
	board[3].state |= board[3].tet;
	return (1);
}

//#define ((tet << offset & ~square) != tet << offset) shift square until tet fits, offset can then be used to shift tet and place; 
//#define ((max_width - offset % map_size) + (max_width - map_size)) jump  tet to start of next line;
/*int ft_place(unsigned short square, int map_size, unsigned short tet)
{
	int				offset;
	unsigned short	mask;

	offset = 0;
	mask = 3 << (map_size - 1);
	if ((mask & (tet << offset)) == mask)
		return (0);
	while ((tet << offset & ~square) != (tet << offset) && offset < max_width * max_width)
	{
		offset++;
		else
			mask = 3 << (map_size - 1);
	}
	if (ft_countbit(tet << offset, map_size) != 4)
	{
		//if not last strip: copy all botom pixels which are >= offset, to tet of next strip and shift tet
		//else ret
		return (0);
	}
	return (tet << offset ^ square);
	}*/

//check if all elements in *tets == 1, causing end of recursion
int	ft_checkend(uint64_t *tets)
{
	int i;

	i = 0;
	while (tets[i] == 1)
	{
		i++;
		if (tets[i] == 0)
			return (1);
	}
	return (0);
}

int	ft_recursive(t_board *board, int map_size, uint64_t *tets, int tc)
{
	t_board		*oldboard;
	uint64_t	tet;
	int			placeret;
	int			ret;

	ft_putstr("BOARD: ");
	ft_putnbr(map_size);
	ft_putendl("");
	print_board(board);
	ft_putendl("");
	if (ft_checkend(tets) == 1)
		return (1);
	oldboard = (t_board *)ft_memalloc(sizeof(t_board) * 4);
	memcpy(oldboard, board, sizeof(t_board) * 4);
	placeret = 0;
	ret = 0;
	tc = 0;
	while (ret == 0)
	{
		memcpy(board, oldboard, sizeof(t_board) * 4);
		while (placeret == 0)
		{
			while (tets[tc] == 1)
				tc++;
			if (tets[tc] == 0)
				return (0);
			ft_putendl("tet");
			print_binary(tets[tc], 4);
			ft_putendl("");
			placeret = ft_placer(board, map_size, tets[tc]);
			tc++;
		}
		tet = tets[tc - 1];
		tets[tc - 1] = 1;
		ret = ft_recursive(board, map_size, tets, 0);
		if (ret == 0)
		{
			ft_putendl("RECURSION:");
			print_board(board);
			ft_putendl("");
			tets[tc - 1] = tet;
		}
	}
	return (ret);
}
