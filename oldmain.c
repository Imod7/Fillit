/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 14:44:26 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/05/31 15:08:22 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
