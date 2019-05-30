/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 14:44:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/05/26 21:45:13 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void				save_tolist(t_list **tetr_lst, unsigned short num)
{
	t_list			*tetrm;

	tetrm = ft_lstnew(&num, 16);
	ft_lstaddend(tetr_lst, tetrm);
}

void				place_tetriminos(t_list **tetr_lst)
{
	t_list			*temp;
	int				x;

	x = 2;
	x = x << 3;
	printf("x = %d\n", x);
	temp = *tetr_lst;
	printf("1st tetr = %d\n", *(unsigned short *)(temp->content));
}

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
			//Checking if there is another bit set (bit = 1)
			//4 positions on the left of this bit
			if (num & (temp >> 4))
				neighbours++;
			//4 positions on the right of this bit
			if (num & (temp << 4))
				neighbours++;
			//1 position on the left of this bit
			if (num & (temp >> 1))
				neighbours++;
			//1 position on the right of this bit
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

int					read_tetrimino(char *buf, unsigned short *n, int bytes)
{
	size_t			j;
	size_t			htags;

	j = 0;
	htags = 0;
	while (j < bytes)
	{
		//Check that between every tetrimino there is a newline
		//and not other characters
		if (j == 20 && buf[j] != '\n')
			return (-1);
		//Check that all characters inside tetrimino are either . or #
		//and that between tetriminos there is not more than 1 newline
		//If it is not endofline & we are not in the newline between the 
		//2 tetriminos (j != 20) & different than . or #
		//then error
		//I put j+1 because of calculation in function isendofline
		if ((endline(j + 1) != 1) && j != 20 && buf[j] != '.' && buf[j] != '#')
			return (-1);
		//If at the end of line there is another character than newline
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
		if (read_tetrimino(buf, &num, bytes_read) == -1)
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
		if (read_tetrimino(buf, &num, bytes_read) == -1)
			return (-1);
		save_tolist(tetr_lst, num);	
		no_of_tetr++;
		return (0);
	}
	//If bytes_read != 21 or bytes_read != 20 or no newline at the EOF
	else
		return (-1);
}

void				print_list(t_list **tetr_lst)
{
	t_list			*temp;
	size_t			i;

	i = 1;
	printf("\n=== Printing Linked List with Tetriminos ===\n\n");
	temp = *tetr_lst;
	while (temp != NULL)
	{
		printf("node %lu -> %d \n", i, *(unsigned short *)(temp->content));
		temp = temp->next;
		i++;
	}
}

int					print_usage(int argc)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	return (1);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_list			*tetr_lst;
	int				output;

	if (print_usage(argc) == 0)
		return (0);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		tetr_lst = NULL;
		output = read_file(fd, &tetr_lst);
		if (output == -1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else
			print_list(&tetr_lst);
		//place_tetriminos(&tetr_lst);
		close(fd);
	}
	return (0);
}
