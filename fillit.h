/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 18:09:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/26 20:15:45 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include "libft.h"

#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET	"\x1b[0m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"

# define max_width			4

typedef struct			s_board
{
	uint64_t			state;
	uint64_t			tet;
}						t_board;

typedef struct			s_tetlist
{
	uint16_t			*tetr;
	short				row;
	short				col;
	struct t_tetlist	*next;
}						t_tetlist;

void					print_list(t_list **tetr_lst);
void					print_binary(unsigned short num, int size);
int						read_file(int fd, t_list **tetr_lst);
int						ft_recursive(t_board *board, int map_size, uint64_t *tets, int tc);
void					ft_putbin(int nb);
void					ft_putsquare(unsigned short square);
uint64_t				shift_to_topleft(uint64_t num);
void					initialize_board(unsigned short **board);
void					print_list(t_list **tetr_lst);
int						check_neighbours(uint64_t num);
uint64_t				tetr_calc(uint64_t j, uint64_t n);
int						endline(int num);
void					print_binary(uint64_t num, int size);
void					save_tolist(t_list **tetr_lst, uint64_t num);

#endif
