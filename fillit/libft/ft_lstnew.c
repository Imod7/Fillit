/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 20:44:12 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/01 19:29:17 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	link = (t_list *)malloc(sizeof(t_list));
	if (link == NULL)
		return (NULL);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
		return (link);
	}
	link->content = malloc(content_size);
	if (link->content == NULL)
		return (NULL);
	ft_memcpy(link->content, content, content_size);
	link->content_size = content_size;
	link->next = NULL;
	return (link);
}
