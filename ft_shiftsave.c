/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shiftsave.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 22:48:53 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/10 22:48:59 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				save_tolist(t_list **tetr_lst, unsigned short num)
{
	t_list			*tetrm;

	tetrm = ft_lstnew(&num, 16);
	ft_lstaddend(tetr_lst, tetrm);
}

unsigned short		shift_to_topleft(unsigned short num)
{
	size_t			i;
	size_t			x;
	size_t			y;
	unsigned short	temp;

	//printf("Tet before shifting \n");
	//print_binary(num, 4);
	//printf("\n");
	i = 0;
	x = 16;
	y = 16;
	while (i < 16)
	{
		temp = num & (1 << i);
		if (temp != 0)
		{
			//printf("temp = %d, pos = %lu \n", temp, i);
			if (i / 4 < y)
				y = i / 4;
			if ((i - (4 * (i / 4))) < x)
				x = i - (4 * (i / 4));
			//printf("i = %lu, x = %lu, y = %lu \n", i, x, y);
			//printf("\n");
		}
		i++;
	}
	num >>= (x + (4 * y));
	//printf("num = %d \n", num);
	//print_binary(num, 4);
	return (num);
}
