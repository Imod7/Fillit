/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putsquare.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 18:54:51 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/11 19:08:44 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsquare(unsigned short square)
{
	int i;

	i = 0;
	while ((unsigned short)((unsigned short)1 << i) != 0)
	{
		if ((unsigned short)(((unsigned short)1 << i) & square) == (unsigned short)1 << i)
			ft_putchar('#');
		else
			ft_putchar('.');
		if ((i + 1) % 4 == 0)
			ft_putchar('\n');
		i++;
	}
}
