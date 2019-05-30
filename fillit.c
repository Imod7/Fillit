/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 14:09:57 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/20 17:20:18 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**tetarr;
	char	**square;
	short	tets;
	int		min_sq;
	int		a;
	short	row;
	short	col;

	col = 0;
	row = 0;
	i = 0;
	a = 6;
	tetarr = (char **)ft_memalloc(sizeof(char *) * 26);
	tetarr[4] = ft_strnew(0);
	if (argc != 2)
		return (0);
	tets = ft_isvalid(&tetarr, open(argv[1], O_RDONLY));
	if (tets == 0)
	{
		ft_putendl("Invalid file");
		return (-1);
	}
	min_sq = tets * 4;
	while (ft_sqrt(min_sq) == 0)
		min_sq++;
	min_sq = ft_sqrt(min_sq);
	square = (char **)ft_memalloc(sizeof(char *) * min_sq);
	ft_putendl("");
	while (row < min_sq)
	{
		square[row] = ft_strnew(min_sq);
		ft_memset(square[row], '.', min_sq);	
		row++;
	}
	ft_putendl("recursion initiation");
	ft_putnbr(ft_recursive(&square, 0, &tetarr));
	ft_putendl("recursion complete");
	while (i < 4)
	{
		ft_putendl(square[i]);
		i++;
	}
	return (0);
}
