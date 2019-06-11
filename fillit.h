/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/18 18:09:47 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/06/11 16:22:00 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef FILLIT_H
# define FILLIT_H

typedef struct			tetr_list
{
	unsigned short		*tetr;
	struct tetr_list	*next;
}						tetris_list;

int						read_file(int fd, t_list **tetr_lst);
int						ft_recursive(unsigned short square, unsigned short offset, unsigned short *tets, int tc);
void					ft_putbin(int nb);
void					ft_putsquare(unsigned short square);
unsigned short			shift_to_topleft(unsigned short num);

#endif
