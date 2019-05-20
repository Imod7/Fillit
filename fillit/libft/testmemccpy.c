/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmemccpy.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 16:50:56 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/03/27 17:27:53 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		main(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	ft_putstr(memccpy(argv[1], argv[2], (int)argv[3] - 48, (size_t)(argv[4] - '0')));
	ft_putstr("precmp");
	if (memccpy(argv[1], argv[2], (int)argv[3] - 48, (size_t)(argv[4] - '0')) == ft_memccpy(argv[1], argv[2], (int)argv[3] - 48, (size_t)(argv[4] - '0')))
		ft_putstr("yeet!");
	else
		ft_putstr("neet!");
	return (0);
}
