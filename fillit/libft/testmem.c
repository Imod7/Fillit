/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memtest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 20:21:37 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/02 16:17:52 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		main(void)
{
	char *str;
	char dest[6] = {'h','a','l','l','o', '\0'};

	str = malloc(5);
	str[0] = 's';
	str[1] = 'k';
	str[2] = '\0';
	str[3] = 'i';
	str[4] = 't';
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr((char *)ft_memcpy((void *)dest, (void *)str, 5));
	ft_putstr(ft_memchr((void *)dest, 105, 4));
	ft_putstr(ft_memcmp("/200", "/0"));
	return (0);
}
