/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testtrim.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 20:32:11 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 17:56:06 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("not the right # of arguments ya dingus");
		return (0);
	}
	//ft_putnbr(ft_strnequ("this is equal", argv[1], 0));
	//ft_putstr(ft_strjoin("hoi ik ben ", argv[1]));
	ft_putstr(ft_strtrim(argv[1]));
	return (0);
}
