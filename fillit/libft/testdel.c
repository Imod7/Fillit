/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testdel.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 12:55:12 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/15 13:31:57 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char *str;

	str = ft_strnew(1);
	str[0] = 'a';
	ft_printmem(str, 4);
	ft_strdel(&str);
	return (0);
}
