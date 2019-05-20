/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testitoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 18:49:43 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 21:29:46 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	ft_putendl(ft_itoa(-5859));
	ft_putendl(ft_itoa(2147483647));
	ft_putendl(ft_itoa(-2147483648));
	ft_putendl(ft_itoa(-2147483647));
	ft_putendl(ft_itoa(0));
	return (0);
}
