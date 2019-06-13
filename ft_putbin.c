/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_base_conv.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 16:54:09 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/13 15:11:42 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_rec(char **str, int nb, int i)
{
	int rest;

	if (nb > 1)
	{
		rest = nb % 2;
		ft_rec(str, nb / 2, i + 1);
		str[0][i] = rest + 48;
	}
	else
		str[0][i] = '1';
}

void	ft_putbin(int nb)
{
	char *str;

	str = ft_strnew(16);
	ft_memset(str, 48, 16);
	ft_rec(&str, nb, 0);
	ft_putendl(str);
	ft_strdel(&str);
}
