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

/*
	read_tet checks for:
		- between every tetrimino there is only one newline
		- all characters in tet are . or #
		- every line of a tet = 4 chars followed by newline 
*/

//read_tetrimino implies that reading happens in the function, but it only checks, so i changed it to check_tet.
//changed j to tet_pos so its more obvious that its the position/index while we iterate the tetrimino bit by bit
//also changed *n to *tet so its more obvious that its the tetrimino (or the number that represents the tetrimino)
int					check_tet(char *buf, uint64_t *tet, int bytes)
{
	int				tet_pos;
	size_t			htags;

	tet_pos = 0;
	htags = 0;
	while (tet_pos < bytes)
	{
		//Check that between every tetrimino there is a newline
		//and not other characters
		if (tet_pos == 20 && buf[tet_pos] != '\n')
			return (-1);
		//Check that all characters inside tetrimino are either . or #
		//and that between tetriminos there is not more than 1 newline
		//If it is not endofline & we are not in the newline between the 
		//2 tetriminos (tet_pos != 20) & different than . or #
		//then error
		//I put tet_pos + 1 because of calculation in function isendofline
		if ((endline(tet_pos + 1) != 1) && tet_pos != 20 && buf[tet_pos] != '.' && buf[tet_pos] != '#')
			return (-1);
		//If at the end of line there is another character than newline
		if ((endline(tet_pos + 1) == 1) && buf[tet_pos] != '\n')
			return (-1);
		if (buf[tet_pos] == '#')
		{
			htags++;
			//printf(" \n we are in pos = %d \n", tet_pos);
			*tet = tetr_calc((uint64_t)tet_pos, *tet);
		}
		tet_pos++;
	}
	if (htags != 4)
		return (-1);
	//printf("\n j = %d , n = %llu   , neighbours = %d \n", j, *n, check_neighbours(*n));
	if (check_neighbours(*tet) < 6)
		return (-1);
	return (0);
}

int					read_file(int fd, t_list **tetr_lst)
{
	int				bytes_read;
	uint64_t		tet;
	char			buf[21];
	int				no_of_tetr;

	no_of_tetr = 0;
	bytes_read = read(fd, buf, 21);
	if (bytes_read == -1)
		return (-1);
	while (bytes_read == 21 && no_of_tetr < 26)
	{
		tet = 0;
		printf(ANSI_COLOR_CYAN "\n========== TETRIMINO => %d ============= \n" ANSI_COLOR_RESET, no_of_tetr);
		printf("buf = '\n%s'\nbytes_read = %d ,tet = %llu \n", buf, bytes_read, tet);
		if (check_tet(buf, &tet, bytes_read) == -1)
			return (-1);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits \n" ANSI_COLOR_RESET);
		printf("tet = %llu \n", tet);
		print_binary(tet, 4);
		tet = shift_to_topleft(tet);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits SHIFTED TOPLEFT \n" ANSI_COLOR_RESET);
		print_binary(tet, 4);
		save_tolist(tetr_lst, tet);
		bytes_read = read(fd, buf, 21);
		if (bytes_read == -1)
			return (-1);
		no_of_tetr++;
	}
	tet = 0;
	if (bytes_read == 20 && buf[19] == '\n' && no_of_tetr < 26)
	{
		printf(ANSI_COLOR_CYAN "\n========== TETRIMINO => %d ============= \n" ANSI_COLOR_RESET, no_of_tetr);
		printf("buf = '\n%s'\nbytes_read = %d ,num = %llu \n", buf, bytes_read, tet);
		if (check_tet(buf, &tet, bytes_read) == -1)
			return (-1);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits \n" ANSI_COLOR_RESET);
		printf("tet = %llu \n", tet);
		print_binary(tet, 4);
		tet = shift_to_topleft(tet);
		printf(ANSI_COLOR_YELLOW "TETRIMINO in 64 bits SHIFTED TOPLEFT \n" ANSI_COLOR_RESET);
		print_binary(tet, 4);
		save_tolist(tetr_lst, tet);	
		no_of_tetr++;
		return (0);
	}
	//If bytes_read != 21 or bytes_read != 20 or no newline at the EOF
	else
		return (-1);
}
