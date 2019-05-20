/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testsub.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 17:47:59 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 17:51:06 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	char str[10] = "hallotest";
	ft_putstr(ft_strsub(str, 4, 4));
	return (0);
}
