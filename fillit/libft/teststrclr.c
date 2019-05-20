/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   teststrclr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 16:20:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 16:26:13 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char str[4] = "hoi";
	ft_strclr(str);
	if (strncmp("\0\0\0\0", str, 4) == 0)
		ft_putstr("yeet");
	return (0);
}
