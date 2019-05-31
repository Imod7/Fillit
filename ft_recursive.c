/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/31 18:55:09 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
int ft_countbit(unsigned short nb)
{
	unsigned short i;
	int count;

	i = 1;
	count = 0;
	while (i != 0)
	{
		if ((i & nb) == i)
			count++;
		i = i << 1;
	}
	return (count);
}

//place tet at first available spot
int ft_place(unsigned short square, unsigned short offset, unsigned short tet)
{
	while ((tet & (unsigned short)32768) != 32768)
		tet = tet << 1;
	ft_putbin(tet);
	while (tet != 0)
	{
		while ((~square << offset & tet) != tet && offset < 17)
			offset++;
		if (ft_countbit(tet >> offset) != 4)
			return (0);
		if ((tet >> offset & 6144) == 6144 || (tet >> offset & 384) == 384 || (tet >> offset & 24) == 24)
		{
			offset++;
			continue ;
		}
		return (tet >> offset ^ square);
	}
	return (0);
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

int	ft_recursive(unsigned short square, unsigned short offset, unsigned short *tets, int tc)
{
	unsigned short newsquare;
	int ret;

	ft_putnbr(tc);
	ft_putendl("square: ");
	ft_putsquare(square);
	if (tc != 0)
		tets[tc - 1] = 1;
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
			newsquare = ft_place(square, offset, tets[tc]);
			tc++;
		}
		ret = ft_recursive(newsquare, offset, tets, tc);
	}
	return (ret);
}
