/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testbin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 18:07:00 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/21 18:28:25 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	char *str;

	str = ft_strnew(16);
	ft_memset(str, 48, 16);
	ft_putbin(&str, 51, 16);
	ft_putendl(str);
	ft_memset(str, 48, 16);
	ft_putbin(&str, 15, 16);
	ft_putendl(str);
	ft_memset(str, 48, 16);
	ft_putbin(&str, 10, 16);
	ft_putendl(str);
	ft_memset(str, 48, 16);
	return (0);
}
