/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_shiftsave.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 22:48:53 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/11 15:19:49 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				save_tolist(t_list **tetr_lst, uint64_t num)
{
	t_list			*tetrm;

	printf("Save tetrimino to the Linked List \n");
	tetrm = ft_lstnew(&num, 64);
	ft_lstaddend(tetr_lst, tetrm);
}

/*
	-- function "shift_to_topleft" --
	Reading the 64-bit number/tetrimino  
	and shifting it to the top left
*/
uint64_t			shift_to_topleft(uint64_t num)
{
	size_t			i;
	size_t			x;
	size_t			y;
	uint64_t		temp;
	
	//printf("Tet before shifting\n");
	//print_binary(num, 4);
	//printf("\n");
	i = 0;
	x = 16;
	y = 16;
	while (i < 64)
	{
		temp = num & ((uint64_t)1 << i);
		if (temp != 0)
		{
			//printf("temp = %llu, pos = %lu \n", temp, i);
			if (i / 4 < y)
			{
				//printf("this is executed \n");
				y = i / 4;
			}
			if ((i - (4 * (i / 4))) < x)
			{
				//printf("this is also executed \n");
				x = i - (4 * (i / 4));
			}
			//printf("i = %lu, x = %lu, y = %lu \n", i, x, y);
			//printf("\n");
		}
		//printf("i = %lu \n", i);
		i++;
	}
	num >>= (x + (4 * y));
	//printf("num = %llu \n", num);
	//print_binary(num, 4);
	return (num);
}
