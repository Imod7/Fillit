/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movetest.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 18:45:45 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 15:32:55 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	int n;
	if (argc == 3)
	{
		n = atoi(argv[2]);
		if (memmove(argv[1], &argv[1][n], ft_strlen(&argv[1][n])))
			ft_putstr("pre-yeet");
		if (memmove(argv[1], &argv[1][n], ft_strlen(&argv[1][n])) == ft_memmove(argv[1], &argv[1][n], ft_strlen(&argv[1][n])))
		{
			ft_putstr("yeet");
		}
	}
	return (0);
}
