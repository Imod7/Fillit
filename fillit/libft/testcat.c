/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testcat.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 18:27:51 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 15:31:12 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char str[10] = "test";
	char str2[10] = "test";
	char str3[10] = "test";
	char str4[10] = "test";
	if (argc != 3)
	{
		ft_putstr("argc");
		return (1);
	}
	ft_putnbr(strlcat(str, argv[1], atoi(argv[2])));
	ft_putchar('\n');
	ft_putendl(str);
	if (strlcat(str2, argv[1], atoi(argv[2])) == ft_strlcat(str3, argv[1], atoi(argv[2])))
		ft_putstr("yeet! ");
	else
		ft_putstr("neet! ");
	ft_putnbr(ft_strlcat(str4, argv[1], atoi(argv[2])));
	ft_putchar('\n');
	ft_putendl(str4);
	return (0);
}
