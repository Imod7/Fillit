/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmemcmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:44:45 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/03/27 17:58:25 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	if (memcmp(argv[1], argv[2], 5) == ft_memcmp(argv[1], argv[2], 5))
		printf("%i", ft_memcmp(argv[1], argv[2], 5));
	else
	{
		printf("%i\n", ft_memcmp(argv[1], argv[2], 5));
		printf("%i", memcmp(argv[1], argv[2], 5));
	}
	return (0);
}
