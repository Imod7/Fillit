/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putsquare.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 18:54:51 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/12 18:21:31 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsquare(unsigned short square, int map_size)
{
	int i;

	i = 0;
	while (i < map_size * map_size)
	{
		if ((unsigned short)(((unsigned short)1 << i) & square) == (unsigned short)1 << i)
			ft_putchar('#');
		else
			ft_putchar('.');
		if ((i + 1) % map_size == 0)
		{
			i += 4 - map_size;
			ft_putchar('\n');
		}
		i++;
	}
}
