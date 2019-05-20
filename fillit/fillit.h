/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 16:15:20 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/05/15 21:35:25 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H

int		ft_isvalid(char ***tetarr, int fd);
int		ft_recursive(char ***square, int offset, char ***tetarr);

#endif
