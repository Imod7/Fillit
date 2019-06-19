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

int					read_tetrimino(char *buf, uint64_t *n, int bytes)
{
	int				j;
	size_t			htags;

	j = 0;
	htags = 0;
	//bytes = 0;
	while (j < bytes)
	//while ((int)j < 9)
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
			//printf(" \n we are in pos = %d \n", j);
			*n = tetr_calc((uint64_t)j, *n);
		}
		j++;
	}
	if (htags != 4)
		return (-1);
	//printf("\n j = %d , n = %llu   , neighbours = %d \n", j, *n, check_neighbours(*n));
	if (check_neighbours(*n) < 6)
		return (-1);
	return (0);
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
	uint64_t		num;
	char			buf[21];
	int				no_of_tetr;

	no_of_tetr = 0;
	bytes_read = read(fd, buf, 21);
	if (bytes_read == -1)
		return (-1);
	while (bytes_read == 21 && no_of_tetr < 26)
	{
		num = 0;
		printf(ANSI_COLOR_CYAN "\n========== TETRIMINO => %d ============= \n" ANSI_COLOR_RESET, no_of_tetr);
		printf("buf = '\n%s'\nbytes_read = %d ,num = %llu \n", buf, bytes_read, num);
		if (read_tetrimino(buf, &num, bytes_read) == -1)
			return (-1);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits \n" ANSI_COLOR_RESET);
		printf("tet = %llu \n", num);
		print_binary(num, 4);
		num = shift_to_topleft(num);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits SHIFTED TOPLEFT \n" ANSI_COLOR_RESET);
		print_binary(num, 4);
		save_tolist(tetr_lst, num);
		bytes_read = read(fd, buf, 21);
		if (bytes_read == -1)
			return (-1);
		no_of_tetr++;
	}
	num = 0;
	if (bytes_read == 20 && buf[19] == '\n' && no_of_tetr < 26)
	{
		printf(ANSI_COLOR_CYAN "\n========== TETRIMINO => %d ============= \n" ANSI_COLOR_RESET, no_of_tetr);
		printf("buf = '\n%s'\nbytes_read = %d ,num = %llu \n", buf, bytes_read, num);
		if (read_tetrimino(buf, &num, bytes_read) == -1)
			return (-1);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits \n" ANSI_COLOR_RESET);
		printf("tet = %llu \n", num);
		print_binary(num, 4);
		num = shift_to_topleft(num);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits SHIFTED TOPLEFT \n" ANSI_COLOR_RESET);
		print_binary(num, 4);
		save_tolist(tetr_lst, num);	
		no_of_tetr++;
		return (0);
	}
	//If bytes_read != 21 or bytes_read != 20 or no newline at the EOF
	else
		return (-1);
}
