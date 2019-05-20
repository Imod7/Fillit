/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testchr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 20:17:31 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 16:05:46 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	if (ft_memchr(argv[1], 999, 6) == memchr(argv[1], 999, 6))
		ft_putstr("Yeet!");
	return (0);
}
