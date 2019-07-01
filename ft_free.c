/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_freelst.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/01 16:01:18 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/07/01 16:25:08 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_free(t_tetlst *tetlst, uint16_t **board)
{
	t_tetlst 	*temp;

	while (tetlst != NULL)
	{
		temp = tetlst;
		tetlst = tetlst->next;
		free(temp);
		temp = NULL;
	}
	free(*board);
	*board = NULL;
}
