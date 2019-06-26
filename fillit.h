/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 18:09:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/26 20:44:15 by ravan-de      ########   odam.nl         */
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
	uint16_t			tet;
	short				row;
	short				col;
	struct s_tetlist	*next;
}						t_tetlist;

void					print_list(t_tetlist **tetr_lst);
void					print_binary(uint16_t num, int size);
int						read_file(int fd, t_tetlist **tetr_lst);
void					ft_putbin(int nb);
uint16_t				shift_to_topleft(uint16_t num);
void					initialize_board(uint16_t **board);
int						initial_boardsize(t_tetlist *tetr_lst);
void					print_list(t_tetlist **tetr_lst);
int						check_neighbours(uint16_t num);
uint16_t				tetr_calc(uint16_t j, uint16_t n);
int						endline(int num);
void					save_tolist(t_tetlist **tetr_lst, uint16_t num);
int						solver(t_tetlist *tetr_lst, uint16_t **board, size_t size);

#endif
