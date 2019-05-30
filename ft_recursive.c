/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_recursive.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 15:24:27 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/30 18:52:33 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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

void	ft_putsquare(unsigned short square)
{
	int i;

	i = 0;
	while (1 << i != 0)
	{
		if ((1 << i & square) == i)
			ft_putchar('#');
		else
			ft_putchar('.');
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
}

//place tet at first available spot
int ft_place(unsigned short square, int offset, unsigned short tet)
{
	while (tet != 0)
	{
		while ((~square >> offset & tet) != tet)
			offset++;
		if ((tet << offset & 6144) == 6144 || (tet << offset & 384) == 384 || (tet << offset & 24) == 24)
			return (0);
		if (ft_countbit(tet << offset) != 4)
			return (0);
		return (tet << offset ^ square);
	}
	return (0);
}

//check if all elements in *tets == 1, causing end of recursion
int	ft_checkend(unsigned short *newtets)
{
	int i;

	i = 0;
	while (newtets[i] == 1)
	{
		i++;
		if (newtets[i] == 0)
			return (1);
	}
	return (0);
}

int	ft_recursive(unsigned short square, int offset, unsigned short *tets, int tc)
{
	unsigned short newsquare;
	int ret;

	ft_putsquare(square);
	if (tc != 0)
		tets[tc - 1] = 1;
	if (ft_checkend(tets) == 1)
		return (square);
	tc = 0;
	ret = 0;
	while (ret == 0)
	{
		newsquare = square;
		while (newsquare == square)
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
