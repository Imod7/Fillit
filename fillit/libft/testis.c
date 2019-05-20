/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testis.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 14:16:44 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:51:47 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "libft.h"

int		main(void)
{
	int i;

	i = 0;
	while (i < 127)
	{
		if (ft_isalpha != isalpha)
			ft_putchar(isalpha(i));
		i++;
	}
	return (0);
}
