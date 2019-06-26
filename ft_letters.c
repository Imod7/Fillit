/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_letters.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/26 19:36:38 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/06/26 20:13:44 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_letters(t_list *lst)
{
	t_list	*begin;
	int		row;
	int		lst_index;
	uint16	pos;

	row = 0;
	lst_index = -1;
	pos = 1;
	begin = lst;
	tet = 0
	while (row < 16)
	{
		while (lst != NULL && pos & lst->tet << lst->row * 16 + lst->col != pos)
		{
			lst = lst->next;
			lst_index++;
		}
		if (lst == NULL)
			ft_putchar('.');
		else
			ft_putchar(lst_index + 65);
		lst = begin;
		lst_index = 0;
		pos = pos << 1;
		if (pos == 0)
		{
			ft_putchar("\n")
			row++;
			pos = 1;
		}
	}
}
