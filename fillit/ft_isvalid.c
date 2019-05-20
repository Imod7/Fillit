/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isvalid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/30 10:58:23 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/20 16:51:58 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>


int	ft_hash(char **blok, int l, int c)
{
	if ((c != 0 && blok[l][c - 1] == '#') || blok[l][c + 1] == '#')
		return (l * 4 + c + 1);
	else if ((l != 0 && blok[l - 1][c] == '#') ||
			(l != 3 && blok[l + 1][c] == '#'))
		return (l * 4 + c + 1);
	else
		return ('n');
}
//checktet: checks for the right characters("." || "#") and returns tet stored
char	*ft_checktet(char **blok)
{
	char		*tet;
	int			hc;
	int			l;
	int			c;

	hc = 0;
	l = 0;
	// tet[4] is reserved for indicating wheter tet has been placed: 1 == placed ; 0 == not placed
	tet = ft_strnew(5);
	while (l != 4)
	{
		c = 0;
		while (c != 4 && hc < 5)
		{
			if (blok[l][c] == '#')
				tet[hc] = ft_hash(blok, l, c);
			hc = ft_strlen(tet);
			c++;
		}
		l++;
	}
	if (hc != 4 || ft_strchr(tet, 'n') != NULL)
	{
		ft_putnbr(hc);
		return (NULL);
	}
	while (tet[0] > 4)
	{
		hc = 0;
		while (hc < 4)
		{
			tet[hc] -= 4;
			hc++;
		}
	}
	while (tet[0] != 1 && tet[1] != 5 && tet[2] != 9 && tet[3] != 13)
	{
		hc = 0;
		while (hc < 4)
		{
			tet[hc] -= 1;
			hc++;
		}
	}
	return (tet);
}

int		ft_clean(char ***blok, int fd)
{
	free(*blok);
	*blok = NULL;
	close(fd);
	return (0);
}
/* bcount is a temp var wich returns the number if test;
   will be replaced by simply counting the number of tets in the tet-array in main;*/

int		ft_isvalid(char ***tetarr, int fd)
{
	int		len;
	int		bcount;
	int		lcount;
	int		ret;
	char	**blok;

	lcount = 0;
	bcount = 0;
	ret = 1;
	blok = ft_memalloc(sizeof(char *) * 5);
	while (ret == 1)
	{
		ret = get_next_line(fd, &blok[lcount]);
		len = ft_strlen(blok[lcount]);
		ft_putendl(blok[lcount]);
		if (len == 4 && lcount != 4)
			lcount++;
		else if (len == 0 && lcount == 4)
		{
			tetarr[0][bcount] = ft_checktet(blok);
			while (lcount > 0)
				ft_strdel(&blok[lcount--]);
			if (tetarr[0][bcount] == NULL)
				return (ft_clean(&blok, fd));
			bcount++;
		}
		else
			return (ft_clean(&blok, fd));
	}
	return (ft_clean(&blok, fd) + bcount);
}
