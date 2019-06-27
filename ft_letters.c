/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_letters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 19:36:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/27 17:54:47 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_seperatet(uint16_t pos, size_t posrow, t_tetlst *lst, size_t lst_index)
{
	size_t		tetrow;
	uint16_t	tetbit;

	tetrow = 0;
	while (tetrow < 4)
	{
		if (tetrow + lst->row == posrow)
		{
			tetbit = (lst->tet << lst->col) >> (tetrow * 16);
			if (!tetbit)
				break ;
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

void	ft_letters(t_tetlst *lst)
{
	t_tetlst	*begin;
	size_t		posrow;
	int			lst_index;
	uint16_t	pos;

	posrow = 0;
	lst_index = 0;
	pos = 1;
	begin = lst;
	while (posrow < 16)
	{
		while (lst != NULL && ft_seperatet(pos, posrow, lst, lst_index) == 0)
		{
			lst = lst->next;
			lst_index++;
		}
		if (lst == NULL)
			ft_putchar('.');
		lst = begin;
		lst_index = 0;
		pos = pos << 1;
		if (pos == 0)
		{
			ft_putchar('\n');
			posrow++;
			pos = 1;
		}
	}
}
