/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testlst.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 20:52:02 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:13:54 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_del(void *data, size_t n)
{
	if (n > 0)
	{
		free(data);
		data = NULL;
	}
}

void	ft_putnbr_elem(t_list *elem)
{
	int *ret;

	ret = (int *)elem->content;
	ft_putnbr(*ret);
}

t_list	*ft_mult(t_list *elem)
{
	int *ret;

	ret = (int *)elem->content;
	*ret *= 10;
	return (ft_lstnew((void *)ret, elem->content_size));
}

int		main(void)
{
	t_list **begin;
	t_list *link;
	int a = 2;
	int b = 4;
	int c = 8;

	link = ft_lstnew(&a, 4);
	begin = &link;
	ft_lstadd(begin, ft_lstnew(&b, 4));
	ft_lstadd(begin, ft_lstnew(&c, 4));
	ft_lstiter(*begin, ft_putnbr_elem);
	ft_putchar('\n');
	ft_lstiter(ft_lstmap(*begin, ft_mult), ft_putnbr_elem);
	ft_lstdel(begin, ft_del);
	if (*begin == NULL)
		ft_putstr("yeet!");
	return (0);
}
