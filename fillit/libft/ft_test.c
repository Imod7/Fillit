/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_test.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 15:55:37 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/24 14:02:08 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

t_fdlist node[N];

void	ft_add(char *data, int fd)
{
	size_t i;

	i = 0;
	while (node[i].fd != 0 && i < N)
		i++;
	node[i].fd = fd;
	ft_strcpy(node[i].rest, data);
}

void	ft_print(void)
{
	size_t n;

	n = 0;
	while (n < N)
	{
		ft_putnbr(node[n].fd);
		ft_putendl(node[n].rest);
		n++;
	}
}

void	func(char *data, int fd)
{
	ft_add(data, fd);
	ft_putendl("current list: ");
	ft_print();
	ft_putendl("");
}
