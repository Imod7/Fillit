/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testatoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 21:43:11 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 15:58:23 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("%ul\n", atoi(argv[1]));
	if (atoi(argv[1]) == ft_atoi(argv[1]))
		ft_putstr("Yeet!");
	printf("%i", ft_atoi(argv[1]));
	return (0);
}
