/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isvalid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 13:10:20 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/19 13:10:25 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//changed num to tet so its obvious that we are referring to the current tetrimino
int					check_neighbours(uint64_t tet)
{
	uint64_t		mask;
	int				neighbours;
	size_t			i;

	neighbours = 0;
	i = 0;
	printf(ANSI_COLOR_YELLOW "Checking neighbours\n" ANSI_COLOR_RESET);
	//print_binary(tet, 4);
	while (i < 64)
	{
		//Checking which bits are set or not
		//we AND the bit with a 1. if the bit is set the result is 1 
		//else is 0.
		mask = tet & ((uint64_t)1 << i);
		//printf(" \n i = %lu, bit = %llu", i, bit);
		if (mask != 0)
		{
			//Checking if there is another bit set (bit = 1)
			//4 positions on the left of this bit
			if (tet & (mask >> (4 + 12)))
				neighbours++;
			//4 positions on the right of this bit
			if (tet & (mask << (4 + 12)))
				neighbours++;
			//1 position on the left of this bit
			if (tet & (mask >> 1))
			{
				neighbours++;
				//printf(" \n one left %d, i= %lu", neighbours, i);
			}
			//1 position on the right of this bit
			if (tet & (mask << 1))
			{
				neighbours++;
				//printf(" \n one right %d , i = %lu", neighbours, i);
			}
		}
		i++;
	}
	printf("n = %llu, neighbours = %d \n", tet, neighbours);
	return (neighbours);
}

/*
	-- function "tetr_calc" --
	Reading the tetrimino bit by bit from file and based on that 
	we calculate the corresponding 64-bit number 
	tet_pos	-> is the bit position/index that we are while iterating the bits of the tetrimino
	tet		-> is our current tetrimino (is a number)
*/
uint64_t			tetr_calc(uint64_t tet_pos, uint64_t tet)
{
	//printf(ANSI_COLOR_YELLOW " \n Tetrimino Calculation " ANSI_COLOR_RESET);
	//printf("=====================================\n");
	//printf("Before Tetr Calc tet = %llu \n", tet);
	//print_binary(tet, 4);
	//printf("\n tet_pos= %llu , tet  = %llu \n\n", tet_pos, tet);
	if (tet_pos >= 19)
	{
		tet |= (uint64_t)1 << (tet_pos - 4 + 12);
		//printf(" 000 domi \n");
	}
	else if (tet_pos >= 14)
	{
		tet |= (uint64_t)1 << (tet_pos - 3 + (12 * 4));
		//printf(" -- domi \n");
	}
	else if (tet_pos >= 9)
	{
		tet |= (uint64_t)1 << (tet_pos - 2 + (12 * 3));
		//printf("domi \n");
	}
	else if (tet_pos >= 4)
	{
		//printf("  SHIFTING = %llu \n", (tet_pos - 1 + (12 * 2)));
		//n |= 1 >> (j - 1 + (12 * 2));
		tet |= (uint64_t)1 << (tet_pos - 1 + (12 * 2));
		//printf("  tet after 31 shift = %llu \n", tet);
	}
	else if (tet_pos < 4)
	{
		tet |= (uint64_t)1 << (tet_pos + 12);
		//printf("j= %lu , n  = %llu \n", j, n);
	}
	//printf("After Tetr Calc : tet = %llu \n", tet);
	//print_binary(tet, 4);
	//printf(" \n\n");
	return (tet);
}

int					endline(int tet)
{
	while (tet > 0)
		tet = tet - 5;
	if (tet == 0)
		return (1);
	return (0);
}