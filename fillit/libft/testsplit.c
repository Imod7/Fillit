/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testsplit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ravan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 15:17:37 by ravan-de      #+#    #+#                 */
/*   Updated: 2019/04/08 17:48:03 by ravan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	size_t 	k;
	char 	**words;
	//char	str[10] = {'h', 'o', 'i', '\0', 'd', 'o', 'e', 'i'};

	k = 0;
	words = ft_strsplit("", '\0');
	if (words == NULL)
		ft_putstr("invalid input");
	while (words[k] != NULL)
	{
		ft_putstr(words[k]);
		k++;
	}
	return (1);
}
