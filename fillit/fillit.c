/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 14:09:57 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/21 18:45:39 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

int	main(void/*int argc, char **argv*/)
{
	int i;
	unsigned short	tet;
	unsigned short	tet2;
	unsigned short	square;
	//int		min_sq;
	short	row;
	short	col;

	i = 0;
	tet = 51;
	tet2 = 51;
	col = 0;
	row = 0;
	square = 0;
	//check argc

	square = tet ^ square;
	ft_putbin(square);
	while ((~square >> i & tet2) != tet2)
		i++;
	square = tet2 << i ^ square;
	ft_putbin(square);
	/*min_sq = tets * 4;
	while (ft_sqrt(min_sq) == 0)
		min_sq++;
	min_sq = ft_sqrt(min_sq);
	*/
	return (0);
}
