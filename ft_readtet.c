/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_readtet.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 14:41:34 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/11 15:21:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

void				save_tolist(t_list **tetr_lst, unsigned short num)
{
	t_list			*tetrm;

	tetrm = ft_lstnew(&num, 16);
	ft_lstaddend(tetr_lst, tetrm);
}

//what is num and i?
int					check_neighbours(unsigned short num)
{
	unsigned short	temp;
	int				neighbours;
	size_t			i;

	neighbours = 0;
	i = 0;
	while (i < 16)
	{
		//Checking which bits are set or not
		//we AND the bit with a 1. if the bit is set the result is 1 
		//else is 0.
		temp = num & (1 << i);
		if (temp != 0)
		{
			//Checking if bit is set
			//4 to left
			if (num & (temp >> 4))
				neighbours++;
			//4 to right
			if (num & (temp << 4))
				neighbours++;
			//1 to left
			if (num & (temp >> 1))
				neighbours++;
			//1 to right
			if (num & (temp << 1))
				neighbours++;
		}
		i++;
	}
	return (neighbours);
}

int					endline(int num)
{
	while (num > 0)
		num = num - 5;
	if (num == 0)
		return (1);
	return (0);
}

//what are j and n?
int					tetr_calc(size_t j, unsigned short n)
{
	if (j >= 19)
		n |= 1 << (j - 4);
	else if (j >= 14)
		n |= 1 << (j - 3);
	else if (j >= 9)
		n |= 1 << (j - 2);
	else if (j >= 4)
		n |= 1 << (j - 1);
	else if (j < 4)
		n |= 1 << j;
	return (n);
}

/*
	read_tet checks for:
		- between every tetrimino there is only one newline
		- all characters in tet are . or #
		- every line of a tet = 4 chars followed by newline 
*/

//read_tetrimino implies that reading happens in the function, but it only checks, so i changed it to check_tet.
//what is j and n?, j is an index but what does int index?
int					check_tet(char *buf, unsigned short *n, size_t bytes)
{
	size_t			j;
	size_t			htags;

	j = 0;
	htags = 0;
	while (j < bytes)
	{
		if (j == 20 && buf[j] != '\n')
			return (-1);
		if ((endline(j + 1) != 1) && j != 20 && buf[j] != '.' && buf[j] != '#')
			return (-1);
		if ((endline(j + 1) == 1) && buf[j] != '\n')
			return (-1);
		if (buf[j] == '#')
		{
			htags++;
			*n = tetr_calc(j, *n);
		}
		j++;
	}
	if (htags != 4)
		return (-1);
	if (check_neighbours(*n) < 6)
		return (-1);
	return (0);
}

int					read_file(int fd, t_list **tetr_lst)
{
	int				bytes_read;
	unsigned short	num;
	char			buf[21];
	int				no_of_tetr;

	no_of_tetr = 0;
	bytes_read = read(fd, buf, 21);
	if (bytes_read == -1)
		return (-1);
	while (bytes_read == 21 && no_of_tetr < 26)
	{
		num = 0;
		if (check_tet(buf, &num, bytes_read) == -1)
			return (-1);
		save_tolist(tetr_lst, num);
		bytes_read = read(fd, buf, 21);
		if (bytes_read == -1)
			return (-1);
		no_of_tetr++;
	}
	num = 0;
	if (bytes_read == 20 && buf[19] == '\n' && no_of_tetr < 26)
	{
		if (check_tet(buf, &num, bytes_read) == -1)
			return (-1);
		num = shift_to_topleft(num);
		save_tolist(tetr_lst, num);	
		no_of_tetr++;
		return (0);
	}
	//If bytes_read != 21 or bytes_read != 20 or no newline at the EOF
	else
		return (-1);
}
