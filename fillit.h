/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 18:09:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/12 16:39:01 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

#define ANSI_COLOR_CYAN		"\x1b[36m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET	"\x1b[0m"
#define ANSI_COLOR_MAGENTA	"\x1b[35m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"

typedef struct			tetr_list
{
	unsigned short		*tetr;
	struct tetr_list	*next;
}						tetris_list;

void					print_list(t_list **tetr_lst);
void					print_binary(unsigned short num, int size);
int						read_file(int fd, t_list **tetr_lst);
int						ft_recursive(unsigned short square, int map_size, unsigned short *tets, int tc);
void					ft_putbin(int nb);
void					ft_putsquare(unsigned short square, int map_size);
unsigned short			shift_to_topleft(unsigned short num);

#endif
