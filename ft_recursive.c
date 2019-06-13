/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/13 15:28:17 by ravan-de      ########   odam.nl         */
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

//count set bits
//when map_size != 4: count fucks up;
int ft_countbit(unsigned short nb, int map_size)
{
	unsigned short i;
	int count;

	i = 1;
	count = 0;
	while (i < 18)
	{
		if (i % (map_size + 1) == 0 && i != 0)
			i += 4 - map_size;
		if ((1 << (i - 1) & nb) == 1 << (i - 1))
			count++;
		i++;
	}
	return (count);
}

//place tet at first available spot
int ft_place(unsigned short square, int map_size, unsigned short tet)
{
	int				offset;
	unsigned short	mask;

	offset = 0;
	mask = 3 << (map_size - 1);
	while ((mask & (tet << offset)) != mask && mask != 1 && mask != 0 && mask != 32768)
		mask = mask >> 4;
	if (mask != 1 && mask != 0 && mask != 32768 && offset > 0)
		offset += 4 - offset % 4 + 4 - map_size;
	else
		mask = 3 << (map_size - 1);
	while ((~square >> offset & tet) != tet && offset < 20)
	{
		offset++;
		while ((mask & (tet << offset)) != mask && mask != 1 && mask != 0 && mask != 32768)
			mask = mask << 4;
		if (mask != 1 && mask != 0 && mask != 32768 && offset > 0)
			offset += 4 - offset % 4 + 4 - map_size;
		else
			mask = 3 << (map_size - 1);
	}
	if (ft_countbit(tet << offset, map_size) != 4)
		return (0);
	return (tet << offset ^ square);
}

//check if all elements in *tets == 1, causing end of recursion
int	ft_checkend(unsigned short *tets)
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

int	ft_recursive(unsigned short square, int map_size, unsigned short *tets, int tc)
{
	unsigned short newsquare;
	unsigned short tet;
	int ret;

	ft_putstr("square ");
	ft_putnbr(map_size);
	ft_putendl(":");
	ft_putsquare(square);
	if (ft_checkend(tets) == 1)
		return (square);
	ret = 0;
	tc = 0;
	while (ret == 0)
	{
		newsquare = square;
		while (newsquare == square || newsquare == 0)
		{
			while (tets[tc] == 1)
				tc++;
			if (tets[tc] == 0)
				return (0);
			ft_putendl("tet:");
			print_binary(tets[tc], 4);
			ft_putendl("");
			newsquare = ft_place(square, map_size, tets[tc]);
			tc++;
		}
		tet = tets[tc - 1];
		tets[tc - 1] = 1;
		ret = ft_recursive(newsquare, map_size, tets, 0);
		if (ret == 0)
		{
			ft_putendl("recursion:");
			ft_putsquare(square);
			tets[tc - 1] = tet;
		}
	}
	return (ret);
}
