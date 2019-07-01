/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_letters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 19:36:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/01 15:53:10 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		tet_cmp(uint16_t pos, size_t posrow, t_tetlst *lst, size_t lst_index)
{
	size_t		tetrow;
	uint16_t	tetbit;

	tetrow = 0;
	if (lst == NULL)
	{
		ft_putchar('.');
		return (1);
	}
	while (tetrow < 4)
	{
		if (tetrow + lst->row == posrow)
		{
			tetbit = (lst->tet << lst->col) >> (tetrow * 16);
			if ((tetbit & pos) == pos)
			{
				ft_putchar(lst_index + 65);
				return (1);
			}
		}
		tetrow++;
	}
	return (0);
}

void	ft_printboard(t_tetlst *lst, size_t size)
{
	t_tetlst	*begin;
	size_t		posrow;
	int			lst_index;
	uint16_t	pos;

	posrow = 0;
	pos = 1;
	begin = lst;
	while (posrow < size)
	{
		lst_index = 0;
		while (tet_cmp(pos, posrow, lst, lst_index) == 0)
		{
			lst = lst->next;
			lst_index++;
		}
		lst = begin;
		pos = pos << 1;
		if (pos == ft_recursive_power(2, size))
		{
			ft_putchar('\n');
			posrow++;
			pos = 1;
		}
	}
}
