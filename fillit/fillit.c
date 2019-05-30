/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 14:09:57 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/30 16:29:04 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

int	main(void/*int argc, char **argv*/)
{
	unsigned short	*tets;
	unsigned short	square;

	test = 0;
	ft_putnbr(sizeof(test));
	tets = malloc(sizeof(unsigned short) * 5);
	tets[0] = 52224;
	tets[1] = 52224;
	tets[2] = 52224;
	tets[3] = 52224;
	tets[4] = 0;
	square = 0;
	//square = ft_recursive(square, 0, tets, 0);
	//ft_putbin(square);
	//check argc
	/*tofill = tets * 4;
	min_sq = 2;
	while (tofill > min_sq * min_sq)
		min_sq++;
	*/
	return (0);
}
