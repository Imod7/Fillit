/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printmem.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 13:25:55 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/15 13:30:10 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmem(char *data, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		if (data[i] == '\0')
		{
			ft_putstr("\0");
		}
		else
			ft_putchar(data[i]);
		i++;
	}
}
