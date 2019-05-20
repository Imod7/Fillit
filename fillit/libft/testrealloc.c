/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testrealloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 18:30:01 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/11 21:01:44 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		main(int argc, char **argv)
{
	char *str;

	if (argc != 3)
		return (1);
	str = ft_strnew(ft_strlen(argv[1]));
	ft_strcpy(str, argv[1]);
	ft_putstr(str);
	str = (char *)ft_realloc(str, ft_strlen(argv[1]) + 1, ft_strlen(argv[2]) + 1);
	ft_strcat(str, argv[2]);
	ft_putstr(str);
	ft_strdel(&str);
	return (0);
}
