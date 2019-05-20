/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testnbr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 18:46:42 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/04 19:29:54 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int		main(void)
{
	int fd;

	ft_putnbr(-2147483647);
	fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(-2147, fd);
	return (0);
}
