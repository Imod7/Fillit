/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testpow.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:40:07 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/21 17:45:34 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_putnbr(ft_recursive_power(ft_atoi(argv[1]), ft_atoi(argv[2])));
	return (0);
}
