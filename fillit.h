/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 18:09:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/27 15:21:27 by ravan-de      ########   odam.nl         */
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


# define MAX_TET		26
# define BUF_SIZE		21

typedef struct			s_tetlst
{
	uint64_t			tet;
	short				row;
	short				col;
	struct s_tetlst		*next;
}						t_tetlst;

void					ft_letters(t_tetlst *tetr_lst);
void					print_list(t_tetlst *tetr_lst);
void					print_binary(uint64_t num, int size);
int						read_file(int fd, t_tetlst **tetr_lst);
int						initialize_board(uint16_t **board, t_tetlst *tetr_lst);
int						check_neighbours(uint64_t num);
uint64_t				tetr_calc(uint64_t tet_pos, uint64_t tet);
int						endline(int num);
void					shiftsave(t_tetlst **tetr_lst, uint64_t num);
int						solver(t_tetlst *tetr_lst, uint16_t **board, size_t size);

#endif
