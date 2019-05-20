
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   teststr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 14:39:26 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 18:11:59 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	char str[20];

	str[0] = 'h';
	str[1] = 'o';
	str[2] = 'i';
	if (argc != 4)
	{
		ft_putstr("Usage: ./teststr [str1] [str2] [n]");
		return (1);
	}
	if (ft_strnstr(argv[1], argv[2], ft_atoi(&argv[3][0])) == strnstr(argv[1], argv[2], ft_atoi(&argv[3][0])))
		ft_putstr("Yeet!");
	else
		ft_putstr("Neet!");
	ft_putstr(ft_strnstr(argv[1], argv[2], ft_atoi(&argv[3][0])));
	return (0);
}
