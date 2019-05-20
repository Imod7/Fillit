/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testlcat.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 19:49:22 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/03/27 20:01:21 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

int		main(void)
{
	char str[7] = "hoi";
	ft_putstr(str);
	ft_putchar('\n');
	if (ft_strlcat(str, "abcdef", 7) == strlcat(str, "abcdef", 7))
		ft_putstr("Yeet!");
	ft_putstr(str);
	return (0);
}
